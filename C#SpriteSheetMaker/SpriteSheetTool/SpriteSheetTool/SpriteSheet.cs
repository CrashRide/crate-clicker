using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;
using System.Drawing;

namespace SpriteSheetTool
{
    public class Box
    {
        public Point start, end;
       
        public int ID;
    }

    public class Sprite
    {
        public string name = string.Empty;
        public int ID;
        public List<Box> animationFrames = new List<Box>();
    }

    public class SpriteSheet
    {

        public SpriteSheet(){}


        public PointF imageScale = new PointF(1.0f, 1.0f);
        public List<Sprite> allSprites = new List<Sprite>();
        public string filePath = string.Empty;

        public void Serialize(string exportFilePath)
        {

            XmlSerializer a_serializer = new XmlSerializer(typeof(SpriteSheet));

            StreamWriter a_streamWriter = new StreamWriter(exportFilePath);

            a_serializer.Serialize(a_streamWriter, this);

            a_streamWriter.Close();            

        }

        public static SpriteSheet Deserialize(string importFilePath)
        {

            XmlSerializer m_capnCrunch = new XmlSerializer(typeof(SpriteSheet));

            StreamReader sReader = new StreamReader(importFilePath);

            SpriteSheet ss = m_capnCrunch.Deserialize(sReader) as SpriteSheet;

            sReader.Close();

            return ss;

        }

    }
}
