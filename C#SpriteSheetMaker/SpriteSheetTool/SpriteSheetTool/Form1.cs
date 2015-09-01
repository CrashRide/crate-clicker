using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Reflection;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;

namespace SpriteSheetTool
{
    public partial class Form_main : Form
    {        
        public Image spriteSheetImage = null;
        public Box currentSelection = null;
        public bool mouseClicked = false;
        public SpriteSheet ssActive = new SpriteSheet();

        //Constructer
        public Form_main()
        {
            InitializeComponent();
            typeof(Panel).InvokeMember("DoubleBuffered", BindingFlags.SetProperty | BindingFlags.Instance | BindingFlags.NonPublic, null, Panel_Editor, new object[] { true });
            ssActive.allSprites.Add(new Sprite());
            ssActive.allSprites[0].name = ("Sprite 1");
            ssActive.allSprites[0].animationFrames.Add(new Box());
        }

        //File->Quit
        private void quitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }


        //Panel Draw
        private void Panel_Editor_Paint(object sender, PaintEventArgs e)
        {
            if(spriteSheetImage != null)
            {
                e.Graphics.DrawImage(spriteSheetImage, 0, 0, (spriteSheetImage.Width * ssActive.imageScale.X), (spriteSheetImage.Height * ssActive.imageScale.Y));
            }

            Pen myPen = new Pen(Color.Yellow);
            foreach (Sprite anim in ssActive.allSprites)
            {
                foreach (Box rect in anim.animationFrames)
                {
                    if (anim.ID == listBoxSprites.SelectedIndex)
                    {
                        myPen.Color = Color.DeepPink;
                        if (rect.ID == listBoxFrames.SelectedIndex)
                        {
                            myPen.Color = Color.DarkViolet;
                        }
                    }
                    else
                        myPen.Color = Color.Yellow;
                    e.Graphics.DrawLine(myPen, rect.start.X, rect.start.Y, rect.end.X, rect.start.Y);
                    e.Graphics.DrawLine(myPen, rect.end.X, rect.start.Y, rect.end.X, rect.end.Y);
                    e.Graphics.DrawLine(myPen, rect.start.X, rect.end.Y, rect.end.X, rect.end.Y);
                    e.Graphics.DrawLine(myPen, rect.start.X, rect.start.Y, rect.start.X, rect.end.Y);
                }
            }

            if (currentSelection != null)
            {
                e.Graphics.DrawLine(myPen, currentSelection.start.X, currentSelection.start.Y, currentSelection.end.X, currentSelection.start.Y);
                e.Graphics.DrawLine(myPen, currentSelection.end.X, currentSelection.start.Y, currentSelection.end.X, currentSelection.end.Y);
                e.Graphics.DrawLine(myPen, currentSelection.start.X, currentSelection.end.Y, currentSelection.end.X, currentSelection.end.Y);
                e.Graphics.DrawLine(myPen, currentSelection.start.X, currentSelection.start.Y, currentSelection.start.X, currentSelection.end.Y);
            }

            myPen.Dispose();
        }


        //Load Image
        private void loadImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialogLoadImage.FileName = "";
            openFileDialogLoadImage.Filter = "All Supported Image Files (*.jpg;*.png;*.bmp)|*.jpg;*.png;*.bmp";

            if(openFileDialogLoadImage.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                spriteSheetImage = Image.FromFile(openFileDialogLoadImage.FileName);
                ssActive.filePath = openFileDialogLoadImage.FileName;
                //Scaling to fit inside Panel
                if(spriteSheetImage.Width > Panel_Editor.Width)
                {
                    ssActive.imageScale.X = ((float)Panel_Editor.Width / (float)spriteSheetImage.Width);
                    ssActive.imageScale.Y = ssActive.imageScale.X;
                    if (spriteSheetImage.Height * ssActive.imageScale.Y > Panel_Editor.Height)
                    {
                        ssActive.imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                        ssActive.imageScale.X = ssActive.imageScale.Y;
                    }
                }
                else if(spriteSheetImage.Height > Panel_Editor.Height)
                {
                    ssActive.imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                    ssActive.imageScale.X = ssActive.imageScale.Y;
                }
                else { ssActive.imageScale.X = 1.0f; ssActive.imageScale.Y = 1.0f; }
                Panel_Editor.Invalidate();
            }
        }


        //Mouse Drag
        private void Panel_Editor_MouseMove(object sender, MouseEventArgs e)
        {
            labelMouseXCoords.Text = e.X.ToString();
            labelMouseYCoords.Text = e.Y.ToString();

            if(mouseClicked)
            {
                currentSelection.end.X = e.X;
                currentSelection.end.Y = e.Y;
                Panel_Editor.Invalidate();
            }
        }


        //Mouse Click
        private void Panel_Editor_MouseDown(object sender, MouseEventArgs e)
        {
            if (listBoxSprites.SelectedItem != null && listBoxFrames.SelectedItem != null)
            {
                mouseClicked = true;

                currentSelection = new Box();
                currentSelection.start.X = currentSelection.end.X = e.X;
                currentSelection.start.Y = currentSelection.end.Y = e.Y;
            }
        }


        //Mouse Release
        private void Panel_Editor_MouseUp(object sender, MouseEventArgs e)
        {
            mouseClicked = false;

            if(currentSelection != null)
            {                
                ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames[listBoxFrames.SelectedIndex].start = currentSelection.start;
                ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames[listBoxFrames.SelectedIndex].end = currentSelection.end;
                currentSelection = null;
                Panel_Editor.Invalidate();
            }
        }

        private void clearFramesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listBoxSprites.SelectedItem != null)
            {
                ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames.Clear();
                listBoxFrames.Items.Clear();
                Panel_Editor.Invalidate();
            }
        }

        private void buttonAddSprite_Click(object sender, EventArgs e)
        {
            Sprite spr = new Sprite();
            spr.ID = ssActive.allSprites.Count;
            spr.name = "Sprite " + (spr.ID + 1).ToString();
            ssActive.allSprites.Add(spr);
            listBoxSprites.Items.Add( spr.name );
            listBoxSprites.SelectedIndex = listBoxSprites.Items.Count - 1;
            Panel_Editor.Invalidate();
        }

        private void buttonRemoveSprite_Click(object sender, EventArgs e)
        {
            if (listBoxSprites.SelectedItem != null)
            {
                int temp = listBoxSprites.SelectedIndex;
                listBoxSprites.Items.RemoveAt(temp);
                ssActive.allSprites.RemoveAt(temp);
                foreach(Sprite anim in ssActive.allSprites)
                {
                    anim.ID = ssActive.allSprites.IndexOf(anim);
                }
                Panel_Editor.Invalidate();
            }
        }

        private void listBoxSprites_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBoxFrames.Items.Clear();
            if (listBoxSprites.SelectedItem != null)
            {
                foreach (Box rect in ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames)
                {
                    listBoxFrames.Items.Add("Frame " + (rect.ID + 1).ToString());
                }
                Panel_Editor.Invalidate();
            }
        }

        private void buttonAddFrame_Click(object sender, EventArgs e)
        {
            if (listBoxSprites.SelectedItem != null)
            {
                Box frm = new Box();
                frm.ID = ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames.Count;
                ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames.Add(frm);
                listBoxFrames.Items.Add("Frame " + (frm.ID + 1).ToString());
                listBoxFrames.SelectedIndex = frm.ID;
                Panel_Editor.Invalidate();
            }
        }

        private void buttonRemoveFrame_Click(object sender, EventArgs e)
        {
            if (listBoxFrames.SelectedItem != null)
            {
                int temp = listBoxFrames.SelectedIndex;
                listBoxFrames.Items.RemoveAt(temp);
                ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames.RemoveAt(temp);
                listBoxFrames.Items.Clear();
                foreach(Box rect in ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames)
                {
                    rect.ID = ssActive.allSprites[listBoxSprites.SelectedIndex].animationFrames.IndexOf(rect);
                    listBoxFrames.Items.Add("Frame " + (rect.ID + 1).ToString());
                }
                Panel_Editor.Invalidate();
            }
        }

        private void listBoxFrames_SelectedIndexChanged(object sender, EventArgs e)
        {
            Panel_Editor.Invalidate();
        }

        private void exportSpriteSheetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialogSSXML.FileName = "";
            saveFileDialogSSXML.Filter = "XML Files (*.xml)|*.xml";

            if(saveFileDialogSSXML.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {

                ssActive.Serialize(saveFileDialogSSXML.FileName);

            }
        }

        private void importSpriteSheetToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialogLoadImage.FileName = "";
            openFileDialogLoadImage.Filter = "XML Files (*.xml)|*.xml";

            if(openFileDialogLoadImage.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {

                ssActive = SpriteSheet.Deserialize(openFileDialogLoadImage.FileName);
                if (ssActive.filePath != string.Empty)
                {
                    spriteSheetImage = Image.FromFile(ssActive.filePath);
                    //Scaling to fit inside Panel
                    if (spriteSheetImage.Width > Panel_Editor.Width)
                    {
                        ssActive.imageScale.X = ((float)Panel_Editor.Width / (float)spriteSheetImage.Width);
                        ssActive.imageScale.Y = ssActive.imageScale.X;
                        if (spriteSheetImage.Height * ssActive.imageScale.Y > Panel_Editor.Height)
                        {
                            ssActive.imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                            ssActive.imageScale.X = ssActive.imageScale.Y;
                        }
                    }
                    else if (spriteSheetImage.Height > Panel_Editor.Height)
                    {
                        ssActive.imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                        ssActive.imageScale.X = ssActive.imageScale.Y;
                    }
                    else { ssActive.imageScale.X = 1.0f; ssActive.imageScale.Y = 1.0f; }
                }
                listBoxSprites.Items.Clear();

                foreach(Sprite anims in ssActive.allSprites)
                {

                    listBoxSprites.Items.Add(anims.name);

                }

                Panel_Editor.Invalidate();

            }
        }     
    }
}
