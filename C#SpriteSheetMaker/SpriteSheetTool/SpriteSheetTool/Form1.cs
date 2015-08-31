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

namespace SpriteSheetTool
{
    public partial class Form_main : Form
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

        public PointF imageScale = new PointF(1.0f, 1.0f);
        public Image spriteSheetImage = null;
        public bool mouseClicked = false;
        public Box currentSelection = null;
        public List<Box> allSelections = new List<Box>();
        public List<Sprite> allSprites = new List<Sprite>();
        

        //Constructer
        public Form_main()
        {
            InitializeComponent();
            typeof(Panel).InvokeMember("DoubleBuffered", BindingFlags.SetProperty | BindingFlags.Instance | BindingFlags.NonPublic, null, Panel_Editor, new object[] { true });
            allSprites.Add(new Sprite());
            allSprites[0].animationFrames.Add(new Box());
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
                e.Graphics.DrawImage(spriteSheetImage, 0, 0, (spriteSheetImage.Width * imageScale.X), (spriteSheetImage.Height * imageScale.Y));
            }

            Pen myPen = new Pen(Color.Yellow);
            foreach (Sprite anim in allSprites)
            {
                foreach (Box rect in anim.animationFrames)
                {
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
                //Scaling to fit inside Panel
                if(spriteSheetImage.Width > Panel_Editor.Width)
                {
                    imageScale.X = ((float)Panel_Editor.Width / (float)spriteSheetImage.Width);
                    imageScale.Y = imageScale.X;
                    if (spriteSheetImage.Height * imageScale.Y > Panel_Editor.Height)
                    {
                        imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                        imageScale.X = imageScale.Y;
                    }
                }
                else if(spriteSheetImage.Height > Panel_Editor.Height)
                {
                    imageScale.Y = ((float)Panel_Editor.Height / (float)spriteSheetImage.Height);
                    imageScale.X = imageScale.Y;
                }
                else { imageScale.X = 1.0f; imageScale.Y = 1.0f; }
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
                allSprites[listBoxSprites.SelectedIndex].animationFrames[listBoxFrames.SelectedIndex] = currentSelection;
                currentSelection = null;
                Panel_Editor.Invalidate();
            }
        }

        private void clearFramesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listBoxSprites.SelectedItem != null)
            {
                allSprites[listBoxSprites.SelectedIndex].animationFrames.Clear();
                listBoxFrames.Items.Clear();
                Panel_Editor.Invalidate();
            }
        }

        private void buttonAddSprite_Click(object sender, EventArgs e)
        {
            Sprite spr = new Sprite();
            spr.ID = allSprites.Count;
            spr.name = "Sprite " + (spr.ID + 1).ToString();
            allSprites.Add(spr);
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
                allSprites.RemoveAt(temp);
                Panel_Editor.Invalidate();
            }
        }

        private void listBoxSprites_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBoxFrames.Items.Clear();
            if (listBoxSprites.SelectedItem != null)
            {
                foreach (Box rect in allSprites[listBoxSprites.SelectedIndex].animationFrames)
                {
                    listBoxFrames.Items.Add("Frame " + (listBoxFrames.Items.Count + 1).ToString());
                }
                Panel_Editor.Invalidate();
            }
        }

        private void buttonAddFrame_Click(object sender, EventArgs e)
        {
            if (listBoxSprites.SelectedItem != null)
            {
                Box frm = new Box();
                frm.ID = allSprites[listBoxSprites.SelectedIndex].animationFrames.Count;
                allSprites[listBoxSprites.SelectedIndex].animationFrames.Add(frm);
                listBoxFrames.Items.Add("Frame " + (listBoxFrames.Items.Count + 1).ToString());
                listBoxFrames.SelectedIndex = listBoxFrames.Items.Count - 1;
                Panel_Editor.Invalidate();
            }
        }

        private void buttonRemoveFrame_Click(object sender, EventArgs e)
        {
            if (listBoxFrames.SelectedItem != null)
            {
                int temp = listBoxFrames.SelectedIndex;
                listBoxFrames.Items.RemoveAt(temp);
                allSprites[listBoxSprites.SelectedIndex].animationFrames.RemoveAt(temp);
                Panel_Editor.Invalidate();
            }
        }      
    }
}
