using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 타율관리프로그램
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        #region 시작 초기화
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.ReadOnly = true;
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
            //
            comboBox3.SelectedIndex = 0;
            textBox4.ReadOnly = true;
            textBox5.ReadOnly = true;
            textBox6.ReadOnly = true;
            textBox7.ReadOnly = true;
            //
            textBox8.ReadOnly = true;
            textBox9.ReadOnly = true;
            textBox10.ReadOnly = true;
            textBox11.ReadOnly = true;
            comboBox4.SelectedIndex = 0;
        }
        #endregion

        #region 선수생성
        /// <summary>
        /// 등번호 생성
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            int id=HitterManager.Singleton.MakeID();
            textBox1.Text = id.ToString();
        }
        /// <summary>
        /// 선수생성
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            Hitter hitter = new Hitter(int.Parse(textBox1.Text), textBox2.Text, (Position)comboBox1.SelectedIndex, (BatType)comboBox2.SelectedIndex);
            HitterManager.Singleton.HitterList.Add(hitter.Id, hitter);
            textBox1.Text = "";
            textBox2.Text = "";
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
        }
        #endregion

        #region 선수 검색
        /// <summary>
        /// 선수 검색
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button3_Click(object sender, EventArgs e)
        {
            if (comboBox3.SelectedIndex == 0)
            {
                listBox1.Items.Clear();
                foreach (KeyValuePair<int,Hitter>hitter in HitterManager.Singleton.HitterList)
                {
                    if(hitter.Key==int.Parse(textBox3.Text))
                    {
                        listBox1.Items.Add(hitter.Key.ToString());
                    }
                }
            }
            else
            {
                listBox1.Items.Clear();
                foreach (KeyValuePair<int, Hitter> hitter in HitterManager.Singleton.HitterList)
                {
                    if (hitter.Value.Name == textBox3.Text)
                    {
                        listBox1.Items.Add(hitter.Key.ToString());
                    }
                }
            }
        }
      
        /// <summary>
        /// 콤보박스 내용 교체시 실행 이벤트
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox3.SelectedIndex == 0)
                label5.Text = "등번호(ID)";
            else
                label5.Text = "이름";
        }
        #endregion

        #region 우측 출력
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int id = int.Parse(listBox1.SelectedItem.ToString());
            Hitter hitter = HitterManager.Singleton.IdToHitter(id);
            TextboxPrint(hitter);
            ListViewPrint(listView1,hitter);
            ListViewPrint(listView2, hitter);
        }
        private void ListViewPrint(ListView listView,Hitter hitter)
        {
            listView.Items.Clear();
            string[] str = new string[]
                {
                    hitter.Hit1.ToString(), hitter.Hit2.ToString(),hitter.Hit3.ToString(),hitter.Homerun.ToString(),
                    hitter.Balls.ToString(),hitter.Dball.ToString(),hitter.Sout.ToString(),hitter.Hout.ToString()
                 };
            ListViewItem lvI = new ListViewItem(str);

            listView.Items.Add(lvI);
        }
        private string posToString(Position pos)
        {
            switch(pos)
            {
                case Position.FIRSTBASEMAN:
                    return "1루수";
                case Position.SECONDBASEMAN:
                    return "2루수";
                case Position.THIRDBASEMAN:
                    return "3루수";
                case Position.SHORTSTOP:
                    return "유격수";
                case Position.LEFTFIELD:
                    return "좌익수";
                case Position.CENTERFIELDER:
                    return "중견수";
                case Position.RIGHTFIELDER:
                    return "우익수";
                case Position.CATCHER:
                    return "포수";
            }
            return "값없음";
        }
        private string typeToString(BatType type)
        {
            switch (type)
            {
                case BatType.LEFT:
                    return "좌타자";
                case BatType.RIGHT:
                    return "우타자";
                case BatType.SWITCH:
                    return "스위치타자";
            }
            return "값없음";
        }
        #endregion

        #region 연산
        private void comboBox4_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox4.SelectedIndex!=0)
            {
                int id = int.Parse(textBox8.Text);
                Hitter hitter = HitterManager.Singleton.IdToHitter(id);
                //항목에 맞는 함수 실행
                switch (comboBox4.SelectedIndex)
                {
                    case 0:
                        {
                            MessageBox.Show("선택을 해줘야합니다.");
                            break;
                        }
                    case 1:
                        {
                            hitter.Hit1count();
                            break;
                        }
                    case 2:
                        {
                            hitter.Hit2count();
                            break;
                        }
                    case 3:
                        {
                            hitter.Hit3count();
                            break;
                        }
                    case 4:
                        {
                            hitter.Homeruncount();
                            break;
                        }
                    case 5:
                        {
                            hitter.Ballscount();
                            break;
                        }
                    case 6:
                        {
                            hitter.Soutcount();
                            break;
                        }
                    case 7:
                        {
                            hitter.HOutcount();
                            break;
                        }
                }
                //출력
                TextboxPrint(hitter);
                ListViewPrint(listView1,hitter);
                ListViewPrint(listView2, hitter);
            }
        }
        #endregion
        
        #region 연산 출력
        private void TextboxPrint(Hitter hitter)
        {
           textBox21.Text = textBox8.Text = textBox4.Text = hitter.Id.ToString();
           textBox22.Text=textBox9.Text = textBox5.Text = hitter.Name;
           textBox23.Text=textBox10.Text = textBox6.Text = posToString(hitter.HitterPosition);
           textBox24.Text=textBox11.Text = textBox7.Text = typeToString(hitter.Battype);
           textBox18.Text=textBox15.Text = textBox12.Text = hitter.PlayCount.ToString();
           textBox19.Text=textBox16.Text = textBox13.Text = hitter.Count.ToString();
           textBox20.Text=textBox17.Text = textBox14.Text = hitter.Average.ToString();
        }
        #endregion

        #region 시뮬레이션
        private void button4_Click(object sender, EventArgs e)
        {
            Hitter hitter = HitterManager.Singleton.IdToHitter(int.Parse(textBox21.Text));
            int SimCount=int.Parse(textBox25.Text);
            HitterManager.Singleton.Simu(SimCount,hitter);

            //출력
            TextboxPrint(hitter);
            ListViewPrint(listView1,hitter);
            ListViewPrint(listView2, hitter);
        }
        #endregion
    }
}
