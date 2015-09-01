namespace SpriteSheetTool
{
    partial class Form_main
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.toolStripMenuFile = new System.Windows.Forms.ToolStripMenuItem();
            this.loadImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importSpriteSheetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportSpriteSheetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.quitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearFramesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.labelMouseX = new System.Windows.Forms.Label();
            this.labelMouseY = new System.Windows.Forms.Label();
            this.labelMouseXCoords = new System.Windows.Forms.Label();
            this.labelMouseYCoords = new System.Windows.Forms.Label();
            this.Panel_Editor = new System.Windows.Forms.Panel();
            this.openFileDialogLoadImage = new System.Windows.Forms.OpenFileDialog();
            this.listBoxFrames = new System.Windows.Forms.ListBox();
            this.listBoxSprites = new System.Windows.Forms.ListBox();
            this.labelSprites = new System.Windows.Forms.Label();
            this.labelFrames = new System.Windows.Forms.Label();
            this.buttonAddSprite = new System.Windows.Forms.Button();
            this.buttonRemoveSprite = new System.Windows.Forms.Button();
            this.buttonRemoveFrame = new System.Windows.Forms.Button();
            this.buttonAddFrame = new System.Windows.Forms.Button();
            this.saveFileDialogSSXML = new System.Windows.Forms.SaveFileDialog();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuFile,
            this.editToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(844, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // toolStripMenuFile
            // 
            this.toolStripMenuFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.loadImageToolStripMenuItem,
            this.importSpriteSheetToolStripMenuItem,
            this.exportSpriteSheetToolStripMenuItem,
            this.quitToolStripMenuItem});
            this.toolStripMenuFile.Name = "toolStripMenuFile";
            this.toolStripMenuFile.Size = new System.Drawing.Size(37, 20);
            this.toolStripMenuFile.Text = "File";
            // 
            // loadImageToolStripMenuItem
            // 
            this.loadImageToolStripMenuItem.Name = "loadImageToolStripMenuItem";
            this.loadImageToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.loadImageToolStripMenuItem.Text = "Load Image";
            this.loadImageToolStripMenuItem.Click += new System.EventHandler(this.loadImageToolStripMenuItem_Click);
            // 
            // importSpriteSheetToolStripMenuItem
            // 
            this.importSpriteSheetToolStripMenuItem.Name = "importSpriteSheetToolStripMenuItem";
            this.importSpriteSheetToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.importSpriteSheetToolStripMenuItem.Text = "Import SpriteSheet";
            this.importSpriteSheetToolStripMenuItem.Click += new System.EventHandler(this.importSpriteSheetToolStripMenuItem_Click);
            // 
            // exportSpriteSheetToolStripMenuItem
            // 
            this.exportSpriteSheetToolStripMenuItem.Name = "exportSpriteSheetToolStripMenuItem";
            this.exportSpriteSheetToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.exportSpriteSheetToolStripMenuItem.Text = "Export SpriteSheet";
            this.exportSpriteSheetToolStripMenuItem.Click += new System.EventHandler(this.exportSpriteSheetToolStripMenuItem_Click);
            // 
            // quitToolStripMenuItem
            // 
            this.quitToolStripMenuItem.Name = "quitToolStripMenuItem";
            this.quitToolStripMenuItem.Size = new System.Drawing.Size(172, 22);
            this.quitToolStripMenuItem.Text = "Quit";
            this.quitToolStripMenuItem.Click += new System.EventHandler(this.quitToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.clearFramesToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // clearFramesToolStripMenuItem
            // 
            this.clearFramesToolStripMenuItem.Name = "clearFramesToolStripMenuItem";
            this.clearFramesToolStripMenuItem.Size = new System.Drawing.Size(142, 22);
            this.clearFramesToolStripMenuItem.Text = "Clear Frames";
            this.clearFramesToolStripMenuItem.Click += new System.EventHandler(this.clearFramesToolStripMenuItem_Click);
            // 
            // labelMouseX
            // 
            this.labelMouseX.AutoSize = true;
            this.labelMouseX.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.labelMouseX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelMouseX.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMouseX.Location = new System.Drawing.Point(661, 60);
            this.labelMouseX.Name = "labelMouseX";
            this.labelMouseX.Size = new System.Drawing.Size(97, 17);
            this.labelMouseX.TabIndex = 1;
            this.labelMouseX.Text = "Mouse X:";
            // 
            // labelMouseY
            // 
            this.labelMouseY.AutoSize = true;
            this.labelMouseY.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.labelMouseY.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelMouseY.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMouseY.Location = new System.Drawing.Point(661, 89);
            this.labelMouseY.Name = "labelMouseY";
            this.labelMouseY.Size = new System.Drawing.Size(97, 17);
            this.labelMouseY.TabIndex = 2;
            this.labelMouseY.Text = "Mouse Y:";
            // 
            // labelMouseXCoords
            // 
            this.labelMouseXCoords.AutoSize = true;
            this.labelMouseXCoords.BackColor = System.Drawing.Color.White;
            this.labelMouseXCoords.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelMouseXCoords.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMouseXCoords.Location = new System.Drawing.Point(762, 60);
            this.labelMouseXCoords.MaximumSize = new System.Drawing.Size(64, 15);
            this.labelMouseXCoords.MinimumSize = new System.Drawing.Size(64, 15);
            this.labelMouseXCoords.Name = "labelMouseXCoords";
            this.labelMouseXCoords.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.labelMouseXCoords.Size = new System.Drawing.Size(64, 15);
            this.labelMouseXCoords.TabIndex = 3;
            this.labelMouseXCoords.Text = "1080";
            // 
            // labelMouseYCoords
            // 
            this.labelMouseYCoords.AutoSize = true;
            this.labelMouseYCoords.BackColor = System.Drawing.Color.White;
            this.labelMouseYCoords.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelMouseYCoords.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelMouseYCoords.Location = new System.Drawing.Point(762, 89);
            this.labelMouseYCoords.MaximumSize = new System.Drawing.Size(64, 15);
            this.labelMouseYCoords.MinimumSize = new System.Drawing.Size(64, 15);
            this.labelMouseYCoords.Name = "labelMouseYCoords";
            this.labelMouseYCoords.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.labelMouseYCoords.Size = new System.Drawing.Size(64, 15);
            this.labelMouseYCoords.TabIndex = 4;
            this.labelMouseYCoords.Text = "1080";
            // 
            // Panel_Editor
            // 
            this.Panel_Editor.BackColor = System.Drawing.Color.DodgerBlue;
            this.Panel_Editor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Panel_Editor.Cursor = System.Windows.Forms.Cursors.Cross;
            this.Panel_Editor.Location = new System.Drawing.Point(12, 37);
            this.Panel_Editor.Name = "Panel_Editor";
            this.Panel_Editor.Size = new System.Drawing.Size(640, 420);
            this.Panel_Editor.TabIndex = 5;
            this.Panel_Editor.Paint += new System.Windows.Forms.PaintEventHandler(this.Panel_Editor_Paint);
            this.Panel_Editor.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Panel_Editor_MouseDown);
            this.Panel_Editor.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Panel_Editor_MouseMove);
            this.Panel_Editor.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Panel_Editor_MouseUp);
            // 
            // openFileDialogLoadImage
            // 
            this.openFileDialogLoadImage.FileName = "openFileDialogLoadImage";
            // 
            // listBoxFrames
            // 
            this.listBoxFrames.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBoxFrames.FormattingEnabled = true;
            this.listBoxFrames.ItemHeight = 15;
            this.listBoxFrames.Items.AddRange(new object[] {
            "Frame 1"});
            this.listBoxFrames.Location = new System.Drawing.Point(691, 323);
            this.listBoxFrames.MaximumSize = new System.Drawing.Size(120, 80);
            this.listBoxFrames.MinimumSize = new System.Drawing.Size(120, 80);
            this.listBoxFrames.Name = "listBoxFrames";
            this.listBoxFrames.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.listBoxFrames.ScrollAlwaysVisible = true;
            this.listBoxFrames.Size = new System.Drawing.Size(120, 79);
            this.listBoxFrames.TabIndex = 6;
            this.listBoxFrames.SelectedIndexChanged += new System.EventHandler(this.listBoxFrames_SelectedIndexChanged);
            // 
            // listBoxSprites
            // 
            this.listBoxSprites.Font = new System.Drawing.Font("Emulogic", 8.249999F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listBoxSprites.ItemHeight = 15;
            this.listBoxSprites.Items.AddRange(new object[] {
            "Sprite 1"});
            this.listBoxSprites.Location = new System.Drawing.Point(691, 157);
            this.listBoxSprites.MaximumSize = new System.Drawing.Size(120, 80);
            this.listBoxSprites.MinimumSize = new System.Drawing.Size(120, 80);
            this.listBoxSprites.Name = "listBoxSprites";
            this.listBoxSprites.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.listBoxSprites.ScrollAlwaysVisible = true;
            this.listBoxSprites.Size = new System.Drawing.Size(120, 79);
            this.listBoxSprites.TabIndex = 7;
            this.listBoxSprites.SelectedIndexChanged += new System.EventHandler(this.listBoxSprites_SelectedIndexChanged);
            // 
            // labelSprites
            // 
            this.labelSprites.AutoSize = true;
            this.labelSprites.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelSprites.Font = new System.Drawing.Font("OCR A Extended", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelSprites.Location = new System.Drawing.Point(703, 135);
            this.labelSprites.Name = "labelSprites";
            this.labelSprites.Size = new System.Drawing.Size(94, 19);
            this.labelSprites.TabIndex = 8;
            this.labelSprites.Text = "Sprites";
            this.labelSprites.UseMnemonic = false;
            // 
            // labelFrames
            // 
            this.labelFrames.AutoSize = true;
            this.labelFrames.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelFrames.Font = new System.Drawing.Font("OCR A Extended", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelFrames.Location = new System.Drawing.Point(704, 301);
            this.labelFrames.Name = "labelFrames";
            this.labelFrames.Size = new System.Drawing.Size(82, 19);
            this.labelFrames.TabIndex = 9;
            this.labelFrames.Text = "Frames";
            this.labelFrames.UseMnemonic = false;
            // 
            // buttonAddSprite
            // 
            this.buttonAddSprite.Location = new System.Drawing.Point(661, 242);
            this.buttonAddSprite.Name = "buttonAddSprite";
            this.buttonAddSprite.Size = new System.Drawing.Size(85, 21);
            this.buttonAddSprite.TabIndex = 10;
            this.buttonAddSprite.Text = "Add Sprite";
            this.buttonAddSprite.UseVisualStyleBackColor = true;
            this.buttonAddSprite.Click += new System.EventHandler(this.buttonAddSprite_Click);
            // 
            // buttonRemoveSprite
            // 
            this.buttonRemoveSprite.Location = new System.Drawing.Point(752, 242);
            this.buttonRemoveSprite.Name = "buttonRemoveSprite";
            this.buttonRemoveSprite.Size = new System.Drawing.Size(87, 21);
            this.buttonRemoveSprite.TabIndex = 11;
            this.buttonRemoveSprite.Text = "Remove Sprite";
            this.buttonRemoveSprite.UseVisualStyleBackColor = true;
            this.buttonRemoveSprite.Click += new System.EventHandler(this.buttonRemoveSprite_Click);
            // 
            // buttonRemoveFrame
            // 
            this.buttonRemoveFrame.Location = new System.Drawing.Point(752, 408);
            this.buttonRemoveFrame.Name = "buttonRemoveFrame";
            this.buttonRemoveFrame.Size = new System.Drawing.Size(87, 21);
            this.buttonRemoveFrame.TabIndex = 13;
            this.buttonRemoveFrame.Text = "Remove Frame";
            this.buttonRemoveFrame.UseVisualStyleBackColor = true;
            this.buttonRemoveFrame.Click += new System.EventHandler(this.buttonRemoveFrame_Click);
            // 
            // buttonAddFrame
            // 
            this.buttonAddFrame.Location = new System.Drawing.Point(661, 408);
            this.buttonAddFrame.Name = "buttonAddFrame";
            this.buttonAddFrame.Size = new System.Drawing.Size(85, 21);
            this.buttonAddFrame.TabIndex = 12;
            this.buttonAddFrame.Text = "Add Frame";
            this.buttonAddFrame.UseVisualStyleBackColor = true;
            this.buttonAddFrame.Click += new System.EventHandler(this.buttonAddFrame_Click);
            // 
            // Form_main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(844, 462);
            this.Controls.Add(this.buttonAddSprite);
            this.Controls.Add(this.buttonRemoveFrame);
            this.Controls.Add(this.buttonAddFrame);
            this.Controls.Add(this.buttonRemoveSprite);
            this.Controls.Add(this.labelFrames);
            this.Controls.Add(this.labelSprites);
            this.Controls.Add(this.listBoxSprites);
            this.Controls.Add(this.listBoxFrames);
            this.Controls.Add(this.Panel_Editor);
            this.Controls.Add(this.labelMouseYCoords);
            this.Controls.Add(this.labelMouseXCoords);
            this.Controls.Add(this.labelMouseY);
            this.Controls.Add(this.labelMouseX);
            this.Controls.Add(this.menuStrip1);
            this.MaximumSize = new System.Drawing.Size(860, 500);
            this.MinimumSize = new System.Drawing.Size(860, 500);
            this.Name = "Form_main";
            this.Text = "SpriteSheet Maker";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuFile;
        private System.Windows.Forms.ToolStripMenuItem loadImageToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importSpriteSheetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportSpriteSheetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem quitToolStripMenuItem;
        private System.Windows.Forms.Label labelMouseX;
        private System.Windows.Forms.Label labelMouseY;
        private System.Windows.Forms.Label labelMouseXCoords;
        private System.Windows.Forms.Label labelMouseYCoords;
        private System.Windows.Forms.Panel Panel_Editor;
        private System.Windows.Forms.OpenFileDialog openFileDialogLoadImage;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearFramesToolStripMenuItem;
        private System.Windows.Forms.ListBox listBoxFrames;
        private System.Windows.Forms.ListBox listBoxSprites;
        private System.Windows.Forms.Label labelSprites;
        private System.Windows.Forms.Label labelFrames;
        private System.Windows.Forms.Button buttonAddSprite;
        private System.Windows.Forms.Button buttonRemoveSprite;
        private System.Windows.Forms.Button buttonRemoveFrame;
        private System.Windows.Forms.Button buttonAddFrame;
        private System.Windows.Forms.SaveFileDialog saveFileDialogSSXML;

    }
}

