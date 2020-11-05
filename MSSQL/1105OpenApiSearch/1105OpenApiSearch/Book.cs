﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1105OpenApiSearch
{
    class Book
    {

        public string Title { get; private set; }
        public string Author { get; private set; }
        public int Price { get; private set; }
        public string Publisher { get; private set; }
        public string Description { get; private set; }
        public string Image { get; private set; }

        public Book(string title, string author, int price, string publisher, string description,string image)
        {
            Title = title;
            Author = author;
            Price = price;
            Publisher = publisher;
            Description = description;
            Image = image;
        }
        static internal Book MakeBook(XmlNode xn)
        {
            string title = string.Empty;
            string author = string.Empty;
            int price = 0;
            string publisher = string.Empty;
            string description = string.Empty;
            string image = string.Empty;

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

            XmlNode image_node = xn.SelectSingleNode("image");
            image = ConvertString(image_node.InnerText);

            return new Book(title, author, price, publisher, description,image);
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
                str = str.Remove(sindex, eindex - sindex + 1);
            }
            return str;
        }

        public override string ToString()
        {
            return Title;
        }
    }
}
