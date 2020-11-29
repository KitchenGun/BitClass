using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.ServiceModel;
using System.Runtime.Serialization;

namespace _1124BookSearchService
{
    [DataContract(Name = "Book")]
    class Book
    {
        [DataMember(Name = "Title", Order = 1, IsRequired = true)]
        public string Title { get; private set; }
        [DataMember(Name = "Author", Order = 2, IsRequired = true)]
        public string Author { get; private set; }
        [DataMember(Name = "Price", Order = 3, IsRequired = true)]
        public int Price { get; private set; }
        [DataMember(Name = "Publisher", Order = 4, IsRequired = true)]
        public string Publisher { get; private set; }
        [DataMember(Name = "Description", Order = 5, IsRequired = true)]
        public string Description { get; private set; }
        [DataMember(Name = "Image", Order = 6, IsRequired = true)]
        public string Image { get; private set; }


        public Book(string title, string author, int price, string publisher, string description, string image)
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
            XmlNode title_node = xn.SelectSingleNode("title");
            string title = ConvertString(title_node.InnerText);
            //string title = title_node.InnerText;

            XmlNode author_node = xn.SelectSingleNode("author");
            string author = ConvertString(author_node.InnerText);
            //string author = author_node.InnerText;

            XmlNode price_node = xn.SelectSingleNode("price");
            int price = int.Parse(price_node.InnerText);

            XmlNode publisher_node = xn.SelectSingleNode("publisher");
            string publisher = ConvertString(publisher_node.InnerText);
            //string publisher = publisher_node.InnerText;

            XmlNode description_node = xn.SelectSingleNode("description");
            string description = ConvertString(description_node.InnerText);
            //string description = description_node.InnerText;

            XmlNode image_node = xn.SelectSingleNode("image");
            string image = ConvertString(image_node.InnerText);

            return new Book(title, author, price, publisher, description, image);
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

    }
}
