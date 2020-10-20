using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1019paintTool
{
    public partial class Form2 : Form
    {
        private List<string> _color = new List<string>();
        private List<string> _shape = new List<string>();
        private List<string> _font = new List<string>();
        public Form2()
        {
            InitializeComponent();
        }
        //초기화(컨트롤 초기화)
        private void Form2_Load(object sender, EventArgs e)
        {
           // cbPenColor.Items.Add("AAA");
            foreach(PropertyInfo prop in typeof(Color).GetProperties())
            {
                if (prop.PropertyType.FullName == "System.Drawing.Color")
                {
                    _color.Add(prop.Name);
                }
            }
            cbPenColor.Items.AddRange(_color.ToArray());
            cbFillColor.Items.AddRange(_color.ToArray());
            cbPenColor.SelectedIndex = -1;
            cbFillColor.SelectedIndex = -1;
            //====================================================
            cbShape.Items.AddRange(new[] { "Line", "Ellipse", "Fill Ellipse", "Rectangle", "Fill Rectangle", "String" });
            //====================================================
            foreach (FontFamily font in FontFamily.Families)
            {

                _font.Add(font.Name);
            }
            cbFont.Items.AddRange(_font.ToArray());
        }
        private void button1_Click(object sender, EventArgs e)
        {
            panel1.Invalidate();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            try
            {
                Pen myPen = new Pen(Color.FromName(cbPenColor.SelectedItem.ToString()));
                SolidBrush myBrush = new SolidBrush(Color.FromName(cbFillColor.SelectedItem.ToString()));

                int x = int.Parse(TBX.Text);
                int y = int.Parse(TBY.Text);
                int width = int.Parse(TBW.Text);
                int height = int.Parse(TBH.Text);

                Graphics g = e.Graphics;

                switch (cbShape.SelectedItem.ToString())
                {
                    case "Line":
                        g.DrawLine(myPen, x, y, width, height);
                        break;
                    case "Ellipse":
                        g.DrawEllipse(myPen, x, y, width, height);
                        break;
                    case "Fill Ellipse":
                        break;
                    case "Rectangle":
                        break;
                    case "Fill Rectangle":
                        break;
                    case "String":
                        {
                            int size = Convert.ToInt32(numericUpDown1.Value);
                            Font font = new Font(cbFont.SelectedItem.ToString(), size, FontStyle.Regular);
                            g.DrawString(TBMain.Text, font, myBrush, x, y);
                        }
                        break;

                }
                myPen.Dispose();
                myBrush.Dispose();
            }
            catch(Exception)
            {

            }
        }
    }
}
