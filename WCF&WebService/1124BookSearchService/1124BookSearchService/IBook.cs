using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.ServiceModel;
using System.Runtime.Serialization;

namespace _1124BookSearchService
{
    [ServiceContract]
    interface IBook
    {
        [OperationContract]
        List<Book> Find(string book_name);

        //[OperationContract]
        //Book BookNameToBook(string bkname);
    }
}
