using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Management;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WorkManager
{
    public partial class Form1 : Form
    {
        private int SecendTimer = 0;
        public Form1()
        {
            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            PrintProcessList();
            timer1.Start();

        }

        //이름\tPID\t시작시간\t\t메모리\t스레드 갯수\t사용자이름\t메모리사용량\t우선순위\tcpu\t상태";
        private void PrintProcessList()
        {
            listView1.Items.Clear();

            int count;
            List<WbProcessData> plist = Wb_Process.Singleton.FinalProcessEnum(out count);
            //리스트뷰에 출력
            foreach (WbProcessData pdata in plist)
            {
                listView1.Items.Add(new ListViewItem(new string[] {
                    pdata.ProcessName, pdata.Id.ToString(), pdata.StartTime.ToString(),
                    pdata.PrivateMemorySize64.ToString(),
                    pdata.ThreadsCount.ToString(), pdata.OwnerName,
                    pdata.WorkingSet64.ToString(),pdata.UserProcessorTime.ToString(),
                    pdata.State
                     }));
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            PrintProcessList();
            CPUusage();
            Memoryusage();
            SecendTimer++;
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            timer1.Stop();
            timer1.Dispose();
        }

        private void 새작업실행NToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //모달
            Form2 dlg = new Form2();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    Wb_Process.Singleton.CreateProcess(dlg.ProcessName);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("프로세스 실행 오류 : " + ex.Message);
                }

            }
            dlg.Dispose();

        }

        private void 끝내기XToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }


        //리스트뷰 정보 갱신
        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        //작업끝내기
        private void button1_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count == 0)
            {
                MessageBox.Show("선택된 항목이 없습니다.");
            }
            else
            {
                ListView.SelectedListViewItemCollection select = listView1.SelectedItems;
                int pid = int.Parse(select[0].SubItems[1].Text);
                Process pr = Wb_Process.Singleton.GetProcessById(pid);
                Wb_Process.Singleton.ExitProcess(pr);
            }
            timer1.Start();
        }

        //CPU 리소스 출력
        private void CPUusage()
        {
            try
            {
                var wmi = new ManagementObjectSearcher("select * from Win32_PerfFormattedData_PerfOS_Processor where Name != '_Total'");
                var cpuUsages = wmi.Get().Cast<ManagementObject>().Select(mo => (long)(ulong)mo["PercentProcessorTime"]);
                var totalUsage = cpuUsages.Average();
                chart1.Series[0].Points.AddXY(SecendTimer, totalUsage);
                graphReset();
                //차트 간격 X : 100, Y : 1000
                chart1.ChartAreas[0].AxisX.Interval = 10;
                chart1.ChartAreas[0].AxisY.Interval = 10;

                //차트 X축 최소값과 최대값, Y축 최소값 최대값 설정
                chart1.ChartAreas[0].AxisY.Minimum = 0;
                chart1.ChartAreas[0].AxisY.Maximum = 100;
                //출력
                label1.Text = "CPU 사용량" + (int)totalUsage + "%";
            }
            catch (Exception)
            {

            }
        }

        //메모리 리소스 출력
        private void Memoryusage()
        {
            int itotalMem = 0; // 총 메모리 KB 단위 
            int itotalMemMB = 0; // 총 메모리 MB 단위 
            int ifreeMem = 0; // 사용 가능 메모리 KB 단위 
            int ifreeMemMB = 0; // 사용 가능 메모리 MB 단위 
            ManagementClass cls = new ManagementClass("Win32_OperatingSystem");
            ManagementObjectCollection moc = cls.GetInstances();
            foreach (ManagementObject mo in moc)
            {
                itotalMem = int.Parse(mo["TotalVisibleMemorySize"].ToString());
                ifreeMem = int.Parse(mo["FreePhysicalMemory"].ToString());
            }
            itotalMemMB = itotalMem / 1024; // 총 메모리 MB 단위 변경 
            ifreeMemMB = ifreeMem / 1024; // 사용 가능 메모리 MB 단위 변경 

            chart2.Series[0].Points.AddXY(SecendTimer, (itotalMemMB - ifreeMemMB) / 1024);
            graphReset();
            //차트 간격 X : 100, Y : 1000
            chart2.ChartAreas[0].AxisX.Interval = 10;
            chart2.ChartAreas[0].AxisY.Interval = 10;

            chart2.ChartAreas[0].AxisY.Minimum = 0;
            chart2.ChartAreas[0].AxisY.Maximum = itotalMemMB / 1024;

            //출력
            label2.Text = "총 메모리량" + itotalMemMB / 1024 + "GB";
            label3.Text = "사용 메모리량" + (itotalMemMB - ifreeMemMB) / 1024 + "GB";
            label4.Text = "여유 메모리량" + ifreeMemMB / 1024 + "GB";
        }

        //그래프 초기화
        private void graphReset()
        {
            if (chart1.Series[0].Points.Count > 60)
            {
                chart1.Series[0].Points.RemoveAt(0);
                //chart1.Series[1].Points.RemoveAt(0);
            }

            //차트 X축 최소값과 최대값, Y축 최소값 최대값 설정
            chart1.ChartAreas[0].AxisX.Minimum = chart1.Series[0].Points[0].XValue;
            chart1.ChartAreas[0].AxisX.Maximum = SecendTimer;


            if (chart2.Series[0].Points.Count > 60)
            {
                chart2.Series[0].Points.RemoveAt(0);
                //chart1.Series[1].Points.RemoveAt(0);
            }

            //차트 X축 최소값과 최대값, Y축 최소값 최대값 설정
            chart2.ChartAreas[0].AxisX.Minimum = chart2.Series[0].Points[0].XValue;
            chart2.ChartAreas[0].AxisX.Maximum = SecendTimer;
        }

    }
}
