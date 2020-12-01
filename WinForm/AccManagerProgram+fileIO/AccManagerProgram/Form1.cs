using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AccManagerProgram
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
            label6.Visible = false;
            textBox1.Visible = false;
            //검색
            comboBox2.SelectedIndex = 0;
            //입출금
            comboBox3.SelectedIndex = 0;
            textBox20.Visible = false;
            label24.Visible = false;
            try
            {
                AccManager.Singleton.Read();
            }
            catch(Exception)
            {

            }
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            AccManager.Singleton.Write();
        }

        #region 계좌 개설
        //[계좌개설]계좌 번호 생성 버튼
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                //타입획득
                AccountType type = (AccountType)comboBox1.SelectedIndex;

                //컨트롤에 전달
                string id = AccManager.Singleton.MakeAccountID(type);
                //컨트롤에 출력
                textBox2.Text = id;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        //[계좌개설]계좌 선택 -콤보 박스
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //정기 입금액 UI처리 (활성,비활성)
            if (comboBox1.SelectedIndex == 2 || comboBox1.SelectedIndex == 3)
                textBox5.ReadOnly = false;
            else
                textBox5.ReadOnly = true;

            //이자율 UI처리(동적생성,제거)
            if (comboBox1.SelectedIndex == 2)
                textBox1.Visible = label6.Visible = true;
            else
                textBox1.Visible = label6.Visible = false;

        }
        //[계좌개설]계좌 생성 버튼
        private void button2_Click(object sender, EventArgs e)
        {
            AccountType type = (AccountType)comboBox1.SelectedIndex;
            string id = textBox2.Text;
            if (id.Equals(string.Empty))
            {
                MessageBox.Show("ID 입력하세요");
                return;
            }
            string name = textBox3.Text;
            int money = int.Parse(textBox4.Text);

            //컨트롤에 전달
            if (AccManager.Singleton.InsertAccount(type, id, name, money) == false)
                MessageBox.Show("계좌 생성 실패(ID중복)");
            else
            {
                comboBox1.SelectedIndex = 0;
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
                textBox5.Text = "";
            }
        }
        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            //이자율 UI처리(동적생성,제거)
            if (comboBox2.SelectedIndex == 0)
                label8.Text = "계좌번호";
            else
                label8.Text = "이름";
        }


        #endregion

        #region 계좌 검색 [좌상단]
        //[계좌검색] 키 입력 핸들러
        private void textBox6_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Enter)
            {
                button3_Click(sender, e);
            }
        }
        //[계좌검색] 검색 요청 버튼
        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                string key = textBox6.Text;

                if (comboBox2.SelectedIndex == 0)   //계좌번호
                {
                    NormalAcc acc = AccManager.Singleton.IdToAccount(key);
                    AccListPrint(acc);
                }
                else //이름
                {
                    List<NormalAcc> acc = AccManager.Singleton.NameToAccount(key);
                    AccListPrint(acc);
                }
            }
            catch (Exception)
            {
            }
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string accid = listBox1.SelectedItem.ToString();
            NormalAcc acc = AccManager.Singleton.IdToAccount(accid);
            //오른쪽에 적절히 출력
            AccInfoTopPrint(acc);
            AccInfoButtomPrint(acc.AccList);
        }
        
        #endregion

        #region  계좌 검색 [좌하단]
        private void AccInfoButtomPrint(List<AccountIOList> acclist)
        {
            listView1.Clear();
            foreach (AccountIOList iolist in acclist)
            {
                listView1.Items.Add(new ListViewItem(new string[] {
                    iolist.Id, iolist.Stime.ToString(),
                    iolist.Input.ToString(), iolist.Output.ToString(),
                    iolist.Balance.ToString()
                     }));
            }

        }

        #endregion

        #region 계좌 출력
        private void AccInfoTopPrint(NormalAcc acc)
        {
            textBox13.Text = textBox7.Text = acc.Type.ToString();
            textBox14.Text = textBox8.Text = acc.Id;
            textBox15.Text = textBox9.Text = acc.Name;
            textBox16.Text = textBox10.Text = acc.Balance.ToString() + "원";//3자리
            textBox17.Text = textBox11.Text = acc.StimeDay;
            textBox18.Text = textBox12.Text = acc.StimeTime;
        }

        private void AccListPrint(NormalAcc acc)
        {
            listBox1.Items.Clear();
            listBox1.Items.Add(acc.Id);
        }

        private void AccListPrint(List<NormalAcc> acc)
        {
            listBox1.Items.Clear();
            foreach (NormalAcc data in acc)
            {
                listBox1.Items.Add(data.Id);
            }
        }
        #endregion

        #region 계좌 검색[우상단 기능]
        //[계좌]입출금 탭으로 이동
        private void button5_Click(object sender, EventArgs e)
        {
            tabControl1.SelectedIndex = 2;
        }

        #endregion

        #region 입출금
        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

            if (comboBox3.SelectedIndex == 0)
            {
                label24.Visible = textBox20.Visible = false;
                label23.Text = "입금액";
            }
            else if (comboBox3.SelectedIndex == 1)
            {
                label24.Visible = textBox20.Visible = false;
                label23.Text = "출금액";
            }
            else if (comboBox3.SelectedIndex == 2)
            {
                label24.Visible = textBox20.Visible = true;
                label23.Text = "이체금액";
            }
        }
        //[입출금] 거래 요청
        private void button4_Click(object sender, EventArgs e)
        {
            string curid      = textBox14.Text;
            int money        = int.Parse(textBox19.Text);
            string transid   = textBox20.Text;
            try
            {
                if (comboBox3.SelectedIndex == 0)//입금
                {
                    AccManager.Singleton.InputMoney(curid, money);
                }
                else if (comboBox3.SelectedIndex == 1)//출금
                {
                    AccManager.Singleton.OutputMoney(curid, money);
                }
                else if (comboBox3.SelectedIndex == 2)//이체
                {
                    AccManager.Singleton.TransMoney(curid,transid, money);
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("거래요청에러 : " + ex.Message);
            }
        }
        #endregion

        #region 삭제
        private void button6_Click(object sender, EventArgs e)
        {
            try
            {
                string id = textBox8.Text;
                AccManager.Singleton.DeleteAccount(id);
                //컨트롤 출력을 초기화
                textBox13.Text = textBox7.Text = "";
                textBox14.Text = textBox8.Text = "";
                textBox15.Text = textBox9.Text = "";
                textBox16.Text = textBox10.Text = "";
                textBox17.Text = textBox11.Text = "";
                textBox18.Text = textBox12.Text = "";
                listView1.Items.Clear();
                listBox1.Items.Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show("삭제오류 : " + ex.Message);

            }

        }
        #endregion

        #region 시뮬레이션
        //전체 계좌 id 획득 후 콤보박스 출력
        private void button8_Click(object sender, EventArgs e)
        {
            comboBox4.Items.Clear();
            foreach (KeyValuePair<string,NormalAcc> data in AccManager.Singleton.AccList)
            {
                comboBox4.Items.Add(data.Key);
            }
        }
        //시뮬레이션 시작
        private void button7_Click(object sender, EventArgs e)
        {
            string id=comboBox4.SelectedItem.ToString();
            int count=int.Parse(textBox21.Text);
            //리턴 정보 lvalue로 획득
            //획득한 정보를 적절히 컨트롤에 출력
            SimulData data=AccManager.Singleton.SimulRun(id, count);

            textBox22.Text = data.Count.ToString();
            textBox23.Text = data.InputCount.ToString();
            textBox24.Text = data.OutputCount.ToString();
            textBox25.Text = data.ResultMoney.ToString();

            //결과보기 버튼
            //해당 계좌의 ID로 검색 -> 거래 정보 획득 
            //그래프를 만들어서 시뮬레이션 결과를 꺾은선 그래프로 출력
            //X좌표 : 횟수, Y좌표는 금액

            //메뉴 : 파일저장, 불러오기- 계좌정보만(입출력정보 제외하고)   

        }
        private void button9_Click(object sender, EventArgs e)
        {
            NormalAcc acc =AccManager.Singleton.IdToAccount(comboBox4.SelectedItem.ToString());
            for(int i=0;i<acc.AccList.Count;i++)
            {
                chart1.Series[0].Points.AddXY(i, acc.AccList[i].Balance);
            }

            //차트 간격
            chart1.ChartAreas[0].AxisX.Interval = 1;
            chart1.ChartAreas[0].AxisY.Interval = 100000;
            //차트 X축 최소값과 최대값, Y축 최소값 최대값 설정
            chart1.ChartAreas[0].AxisY.Minimum = 0;
            chart1.ChartAreas[0].AxisY.Maximum = 1000000;
            //차트 X축 최소값과 최대값, Y축 최소값 최대값 설정
            chart1.ChartAreas[0].AxisX.Minimum = chart1.Series[0].Points[0].XValue;
            chart1.ChartAreas[0].AxisX.Maximum = acc.AccList.Count;

        }


        #endregion

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
