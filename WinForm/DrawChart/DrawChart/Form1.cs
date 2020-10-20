using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;


namespace DrawChart
{
    //https://studymake.tistory.com/467
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            chart1.Series.Clear(); //default series를 삭제한다.
            Series sSin = chart1.Series.Add("sin"); //새로운 series 생성
            sSin.ChartType = SeriesChartType.Line; //그래프 모양을 '선'으로 지정
                                                   //데이터 포인트 저장
            for (double k = 0; k < 2 * Math.PI; k += 0.1)
            {
                sSin.Points.AddXY(k, Math.Sin(k));
            }

        }
    }
}
