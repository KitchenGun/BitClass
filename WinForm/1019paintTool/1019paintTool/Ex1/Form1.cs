using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1019paintTool
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //도형 그리기
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                //컨트롤에 전달:저장
                ShapeControl.Singleton.ShapeInsert(this, e.X, e.Y);
                //화면 출력 요청
                Invalidate();
            }
        }
        //무효화 처리
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //컨트롤에 출력 요청
            ShapeControl.Singleton.ShapePrintAll(e.Graphics);
        }
        //키보드 입력 처리
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            ShapeControl.Singleton.ShapeSizeUpdate(e.KeyCode);
        }

        private void 프로그램종료XToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        //r b g 통합 해서 공통 핸들러 제작
        private void redRToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(redRToolStripMenuItem==sender|| redRToolStripMenuItem1==sender)
            {
                ShapeControl.Singleton.PenColorUpdate(Color.FromArgb(255, 0, 0));
                toolStripStatusLabel1.Text = "빨강";
            }
            else if(blueBToolStripMenuItem == sender || blueBToolStripMenuItem1 == sender)
            {
                ShapeControl.Singleton.PenColorUpdate(Color.FromArgb(0, 0, 255));
                toolStripStatusLabel1.Text = "파랑";
            }
            else if (greenGToolStripMenuItem == sender || greenGToolStripMenuItem1 == sender)
            {
                ShapeControl.Singleton.PenColorUpdate(Color.FromArgb(0, 255, 0));
                toolStripStatusLabel1.Text = "초록";
            }
        }
        //메뉴 상태 처리 핸들러
        private void menuStrip1_MenuActivate(object sender, EventArgs e)
        {
            Color c =ShapeControl.Singleton.CurShape.PenColor;
            redRToolStripMenuItem.Enabled = (c != Color.FromArgb(255,0,0));
            blueBToolStripMenuItem.Enabled = (c != Color.FromArgb(0, 0, 255));
            greenGToolStripMenuItem.Enabled = (c != Color.FromArgb(0, 255, 0));

        }
        //컨텍스트메뉴 상태처리
        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {
            Color c = ShapeControl.Singleton.CurShape.PenColor;
            redRToolStripMenuItem1.Checked = (c == Color.FromArgb(255, 0, 0));
            blueBToolStripMenuItem1.Checked = (c == Color.FromArgb(0, 0, 255));
            greenGToolStripMenuItem1.Checked = (c == Color.FromArgb(0, 255, 0));
        }
        //색상 선택
        private void 색상선택ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //공통다이얼로그 -Modal
            ColorDialog dlg = new ColorDialog();
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                ShapeControl.Singleton.PenColorUpdate(dlg.Color);
                toolStripStatusLabel1.Text = dlg.Color.ToString();
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            ShapeControl.Singleton.PenColorUpdate(Color.FromArgb(255, 0, 0));
        }
    }
}
