using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using _1125WCFChatForm.ServiceReference1;

namespace _1125WCFChatForm
{
    public partial class Form1 : Form,IChatCallback
    {
        private ChatClient proxy;
        public string NickName { get; set; }

        public Form1()
        {
            InitializeComponent();
            //이중계약 계약 객체 생성
            proxy = new ChatClient(new InstanceContext(this));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string nickname = textBox1.Text;
                if (nickname == "") nickname = "무명";

                //서버 접속
                if (proxy.Join(nickname) == false)
                    new Exception("연결 오류");
            }
            catch (Exception)
            {

            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                proxy.Leave(NickName);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                string msg = textBox2.Text;
                proxy.Say(NickName, msg);
                textBox2.Text = "";
            }
            catch (Exception)
            {
                MessageBox.Show("먼저 대화에 참여하세요");
            }
        }

        void IChatCallback.Receive(string idx, string message)
        {
            string msg = string.Format("[{0}] {1}", idx, message);
            listBox1.Items.Add(msg);
        }
        #region 서비스에 의해 호출되는 콜백 함수들                     
        void IChatCallback.UserEnter(string idx)
        {
            string msg = string.Format("{0}님이 대화에 참여하셨습니다.", idx);
            listBox1.Items.Add(msg);
        }

        void IChatCallback.UserLeave(string idx)
        {
            string msg = string.Format("{0}님이 대화방에서 나가셨습니다.", idx);
            listBox1.Items.Add(msg);
        }
        #endregion
    }
}
