using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace _0426_RSS
{
    class MyRSS
    {
        XmlReader reader = null;

        public void RecvRss(string dns)
        {
            XmlUrlResolver resolver = new XmlUrlResolver();
            resolver.Credentials = System.Net.CredentialCache.DefaultCredentials;
            XmlReaderSettings settings = new XmlReaderSettings();
            settings.XmlResolver = resolver;
            reader = XmlReader.Create(dns, settings);      
        }

        public List<string> RecvElement(string elementname)
        {
            List<string> list = new List<string>();
            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element)
                {
                    if (reader.Name == elementname)
                    {
                        Console.WriteLine("--->출력 : " + reader.Name);
                        Console.WriteLine("---ReadInnerXml 호출 결과---");
                        list.Add(reader.ReadInnerXml());
                    }
                }
            }
            reader.Close();
            return list;
        }
    }
}
