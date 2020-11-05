﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace _1105OpenApiSearch
{
    class WbSearchBook
    {
        public List<Book> BookList { get; set; }
        public string BookName { get; private set; }

        public WbSearchBook()
        {
            BookList = new List<Book>();
        }
        public void Find(string book_name, out string xmlstring)
        {
            //1. 검색어를 저장
            BookName = book_name;
            BookList.Clear();

            //2. 검색어로 OpenAPI호출 -> xml문서 획득(xmlstring)
            string query = book_name; // 검색할 문자열
            //string url = "https://openapi.naver.com/v1/search/book?query=" + query; // 결과가 JSON 포맷
            string url = "https://openapi.naver.com/v1/search/book.xml?query=" + query + "&display=20&start=1";  // 결과가 XML 포맷
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "xsiydKFMMsK_kdH5Ub_j"); // 클라이언트 아이디
            request.Headers.Add("X-Naver-Client-Secret", "4SpDRMc0VQ");       // 클라이언트 시크릿
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            string status = response.StatusCode.ToString();
            if (status == "OK")
            {
                Stream stream = response.GetResponseStream();
                StreamReader reader = new StreamReader(stream, Encoding.UTF8);
                xmlstring = reader.ReadToEnd();     //<===============================              
            }
            else
            {
                xmlstring = "";         //<=======================================
                MessageBox.Show("Error 발생=" + status);
            }

            //3.  xml문서를 dompaser로 파싱
            MemoryStream ms = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(xmlstring));
            XmlDocument doc = new XmlDocument();
            doc.Load(ms);
            XmlNode node = doc.SelectSingleNode("rss");
            XmlNode n = node.SelectSingleNode("channel");

            Book book = null;
            foreach (XmlNode el in n.SelectNodes("item"))
            {
                book = Book.MakeBook(el);
                BookList.Add(book);
            }
        }

        public Book BookNameToBook(string bkname)
        {
            foreach (Book b in BookList)
            {
                if (b.Title.Equals(bkname) == true)
                    return b;
            }
            return null;
        }

    }
}
