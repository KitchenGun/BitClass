using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace _1124PictureService
{
    [ServiceContract]
    interface IPicture
    {
        [OperationContract]
        byte[] GetPicture(string strFileName);
        [OperationContract]
        string[] GetPictureList();
        [OperationContract]
        bool UploadPicutre(string strFileName, byte[] bytePic);

    }
}
