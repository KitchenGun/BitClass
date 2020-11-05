using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace OpenAPI1105
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //string jsonstr=WbPapago.Sample(textBox1.Text,"ko","en");
            string jsonstr = WbPapago.Sample(textBox1.Text, "en", "ko");
            //방법1
            JObject jobj = JObject.Parse(jsonstr);
            textBox2.Text = jobj["message"]["result"]["translatedText"].ToString();
            //방법 2

        }
    }
}
