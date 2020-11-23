<%@ WebService Language="C#" Class="PictureService" %>

using System;
using System.Collections.Generic;
using System.IO;
using System.Web;
using System.Web.Services;

public class PictureService : System.Web.Services.WebService
{
    public PictureService() {
       
    }

    [WebMethod]
    public byte[] GetPicture(string strFileName)
    {
        byte[] bytePic = { 0 }; // ����Ʈ �迭�� �ϳ� �����.
        try
        {
            // �ش� �̹��� ������ ��Ʈ�� �������� �����Ѵ�.
            FileStream picFileStream = new
                FileStream(@"D:\Git\��Ʈ\BitClass\WCF&WebService\IIS\Image\" + strFileName, FileMode.Open,FileAccess.Read, FileShare.Read);
            //  FileStream("C:\\AAA\\Image\\" + strFileName, FileMode.Open, FileAccess.Read, FileShare.Read);

            // �̹��� ���� ��Ʈ���� ���� ��ü�� �ϳ� �����.
            BinaryReader picReader = new BinaryReader(picFileStream);
            
            // �̹��� ������ ����Ʈ �迭�� �ִ´�.
            bytePic = picReader.ReadBytes(Convert.ToInt32(picFileStream.Length));
            // ���Ͻ�Ʈ���� �ݴ´�.
            picFileStream.Close();
            // �̹��� ������ ����ִ� ����Ʈ �迭�� �����Ѵ�.
            return bytePic;
        }
        catch
        {
            // �ʱⰪ�� �׳� �����Ѵ�.
            return bytePic;
        }

    }

    [WebMethod]
    public string[] GetPictureList()
    {
        // �̹��� ������ ����ִ� ���丮���� ���� �̸����� ���ڿ� �迭�� �ִ´�.
        string[] strPicList = Directory.GetFiles(@"D:\Git\��Ʈ\BitClass\WCF&WebService\IIS\Image");

        // ���� ��θ� �� ���� �̸��� �ٽ� �����Ѵ�.
        for (int i = 0; i < strPicList.Length; i++)
        {
            FileInfo fi = new FileInfo(strPicList[i]);
            strPicList[i] = fi.Name;
        }
        // �� �̹��� ���� �̸����� �����Ѵ�.
        return strPicList;

    }

    [WebMethod]
    public bool UploadPicture(string strFileName, byte[] bytePic)
    {
        try
        {
            // �־��� �̹��� ������ �̸����� ������ �ϳ� �����.
            FileStream writeFileStream = new FileStream(@"D:\Git\��Ʈ\BitClass\WCF&WebService\IIS\Image" + strFileName, FileMode.Create,FileAccess.Write);

            // �� ���Ͽ� ���̳ʸ��� �ֱ� ���� BinaryWriter ��ü ����
            BinaryWriter picWriter = new BinaryWriter(writeFileStream);
            // ����Ʈ �迭�� ���� �̹����� ���Ͽ� ����.
            picWriter.Write(bytePic);
            // ���Ͻ�Ʈ���� �ݴ´�.
            writeFileStream.Close();
            // ���ε� ����
            return true;
        }
        catch (Exception )
        {
            // ���ε� ����
            return false;
        }
    }
}