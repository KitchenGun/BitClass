using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.ServiceModel;

namespace _1124BookSearchService
{
    
    class SearchBook : IBook
    {
        public List<Book> BookList { get; set; }
        public string BookName { get; private set; }

        

        public SearchBook()
        {
            BookList = new List<Book>();
        }

        public List<Book> Find(string book_name)
        {
            //1. 검색어를 저장
            BookList.Clear();
            string xmlstring;

            //2. 검색어로 OpenAPI호출 -> xml문서 획득(xmlstring)
            string query = book_name; // 검색할 문자열
            //string url = "https://openapi.naver.com/v1/search/book?query=" + query; // 결과가 JSON 포맷
            string url = "https://openapi.naver.com/v1/search/book.xml?query=" + query + "&display=20&start=1";  // 결과가 XML 포맷
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            
            request.Headers.Add("X-Naver-Client-Id", "sdUxKYgwTDvXr1SMhfPu"); // 클라이언트 아이디
            request.Headers.Add("X-Naver-Client-Secret", "wrstyqYvoZ");       // 클라이언트 시크릿
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
            }

            //3.  xml문서를 dompaser로 파싱
            // MemoryStream ms = new MemoryStream(System.Text.Encoding.UTF8.GetBytes(xmlstring));
            XmlDocument doc = new XmlDocument();
            doc.LoadXml(xmlstring);

            XmlNode node = doc.SelectSingleNode("rss");
            XmlNode n = node.SelectSingleNode("channel");


            foreach (XmlNode el in n.SelectNodes("item"))
            {
                Book book = Book.MakeBook(el);
                BookList.Add(book);
            }

            return BookList;
        }

    }
}
