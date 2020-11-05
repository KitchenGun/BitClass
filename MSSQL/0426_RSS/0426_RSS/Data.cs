using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _0426_RSS
{
    class Data
    {
        public string Title { get; set; }
        public string Link { get; set; }
        public string Description { get; set; }
        public string Date { get; set;  }
        public string Author { get; set; }
        public string Category { get; set; }
        public string PubDate { get; set; }

        public string Image { get; set;  }
        
        public Data(string t, string l, string d, string _date, string a, string c, string p , string i)
        {
            Title = t;
            Link = l;
            Description = d;
            Date = _date;
            Author = a;
            Category = c;
            PubDate = p;
            Image = i;
        }
    }
}
