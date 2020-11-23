using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _1123WindowsForm.localhost;

namespace _1123WindowsForm
{

    public partial class PicListForm : Form
    {

        public string SelectedPic
        {
            get
            {
                return listBox1.SelectedItem.ToString();
            }
        }
        // PictureService 객체를 하나 생성
        PictureService pic = new PictureService();

        public PicListForm()
        {
            InitializeComponent();
            // 이미지 파일의 목록을 가져오는 메소드를 호출해서 문자열 배열에 저장한다.
            string[] strPicList = pic.GetPictureList();
            listBox1.DataSource = strPicList;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
            Close();
        }

        private void listBox1_DoubleClick(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
            Close();
        }
    }

   

}
