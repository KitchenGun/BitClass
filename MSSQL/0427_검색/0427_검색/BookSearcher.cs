using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Windows.Forms;
using System.Xml;

namespace _0427_검색
{
    class BookSearcher
    {
        List<Book> booklist;

        internal BookSearcher()
        {
            booklist = new List<Book>();
        }

        internal void Find(string book_name)
        {
            string url = "https://openapi.naver.com/v1/search/book.xml?query=" + book_name;  // 결과가 XML 포맷
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "2NAXViXl2SZVVXzTpCVK"); // 클라이언트 아이디
            request.Headers.Add("X-Naver-Client-Secret", "SUZpkdzRGt");       // 클라이언트 시크릿
            //HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            //string status = response.StatusCode.ToString();
           // if (status == "OK")
            //{
             //   Stream stream = response.GetResponseStream();
              //  StreamReader reader = new StreamReader(stream, Encoding.UTF8);
               // string text = reader.ReadToEnd();
                //=====================================================================
                XmlDocument document = new XmlDocument();
                using (Stream s = request.GetResponse().GetResponseStream())
                {
                    using (XmlReader r = XmlReader.Create(s))
                    {
                        document.Load(r);
                        XmlNode node = document.SelectSingleNode("rss");
                        XmlNode n = node.SelectSingleNode("channel");
                        Book book = null;

                        booklist.Clear();
                        foreach (XmlNode el in n.SelectNodes("item"))
                        {
                            book = Book.MakeBook(el);
                            booklist.Add(book);
                        }
                    }
                }
                //=====================================================================
          //  }
          //  else
           // {
            //    Console.WriteLine("Error 발생=" + status);
           // }

            //this.book_name = book_name;
            //string query = string.Empty;
            //query = string.Format("https://openapi.naver.com/v1/search/blog.xml?query={0}&display=10&start=1&sort=sim&X-Naver-Client-Id={1}&X-Naver-Client-Secret={2}", book_name, "2NAXViXl2SZVVXzTpCVK", "SUZpkdzRGt");
            //MessageBox.Show(query);
            //XmlDocument doc = new XmlDocument();
            //doc.Load(query);
            //XmlNode node = doc.SelectSingleNode("rss");
            //XmlNode n = node.SelectSingleNode("channel");
            //Book book = null;
            
            //booklist.Clear();
            //foreach (XmlNode el in n.SelectNodes("item"))
            //{
            //    book = Book.MakeBook(el);
            //    booklist.Add(book);
            //}
        }
   
        internal void TitlePrint(ListBox listBox1)
        {
            listBox1.Items.Clear();
            foreach(Book book in booklist)
            {
                listBox1.Items.Add(book.Title);
            }
        }

        internal Book GetBookInfo(int idx)
        {
            return booklist[idx];
        }
    }
}
