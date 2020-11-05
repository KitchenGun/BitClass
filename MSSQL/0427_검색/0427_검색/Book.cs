using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace _0427_검색
{
    class Book
    {
        internal string Title
        {
            get;
            private set;
        }
        internal string Author
        {
            get;
            private set;
        }
        internal int Price
        {
            get;
            private set;
        }
        internal string Publisher
        {
            get;
            private set;
        }
        internal string Description
        {
            get;
            private set;
        }
     
        static internal Book MakeBook(XmlNode xn)
        {
            string title = string.Empty;
            string author = string.Empty;
            int price = 0;
            string publisher = string.Empty;
            string description = string.Empty;
            XmlNode title_node = xn.SelectSingleNode("title");
            title = ConvertString(title_node.InnerText);
            XmlNode author_node = xn.SelectSingleNode("author");
            author = ConvertString(author_node.InnerText);
            XmlNode price_node = xn.SelectSingleNode("price");
            price = int.Parse(price_node.InnerText);
            XmlNode publisher_node = xn.SelectSingleNode("publisher");
            publisher = ConvertString(publisher_node.InnerText);
            XmlNode description_node = xn.SelectSingleNode("description");
            description = ConvertString(description_node.InnerText);
            return new Book(title, author, price, publisher, description);
        }
  
        internal Book(string title, string author, int price, string publisher, string description)
        {
            Title = title;
            Author = author;
            Price = price;
            Publisher = publisher;
            Description = description;
        }

        private static string ConvertString(string str)
        {
            int sindex = 0;
            int eindex = 0;
            while (true)
            {
                sindex = str.IndexOf('<');
                if (sindex == -1)
                {
                    break;
                 }
                eindex = str.IndexOf('>');
                str = str.Remove(sindex, eindex - sindex+1);
            }
            return str;
        }

        public override string ToString()
        {
            return Title;
        }
    }
}
