using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1014_1
{
    public partial class GDIExam1 : Form
    {
        public GDIExam1()
        {
            InitializeComponent();

            this.Text = "Graphics 개체 얻기1";
            // paint 이벤트 핸들러 등록
            this.Paint += new PaintEventHandler(GDIExam_Paint);

        }
        public void GDIExam_Paint(object sender, PaintEventArgs pea)
        {
            Graphics grfx = pea.Graphics;
            grfx.FillRectangle(new SolidBrush(Color.Blue), this.ClientRectangle);
        }
    }
}
