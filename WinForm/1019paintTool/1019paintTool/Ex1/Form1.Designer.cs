namespace _1019paintTool
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.파일FToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.프로그램종료XToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.팬색상PToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.blueBToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.greenGToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.색상선택SToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.redRToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.greenGToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.blueBToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.색상선택ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.파일FToolStripMenuItem,
            this.팬색상PToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            this.menuStrip1.MenuActivate += new System.EventHandler(this.menuStrip1_MenuActivate);
            // 
            // 파일FToolStripMenuItem
            // 
            this.파일FToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.프로그램종료XToolStripMenuItem});
            this.파일FToolStripMenuItem.Name = "파일FToolStripMenuItem";
            this.파일FToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
            this.파일FToolStripMenuItem.Text = "파일(&F)";
            // 
            // 프로그램종료XToolStripMenuItem
            // 
            this.프로그램종료XToolStripMenuItem.Name = "프로그램종료XToolStripMenuItem";
            this.프로그램종료XToolStripMenuItem.Size = new System.Drawing.Size(161, 22);
            this.프로그램종료XToolStripMenuItem.Text = "프로그램종료(&X)";
            this.프로그램종료XToolStripMenuItem.Click += new System.EventHandler(this.프로그램종료XToolStripMenuItem_Click);
            // 
            // 팬색상PToolStripMenuItem
            // 
            this.팬색상PToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.redRToolStripMenuItem,
            this.blueBToolStripMenuItem,
            this.greenGToolStripMenuItem,
            this.색상선택SToolStripMenuItem});
            this.팬색상PToolStripMenuItem.Name = "팬색상PToolStripMenuItem";
            this.팬색상PToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.팬색상PToolStripMenuItem.Text = "팬색상(&P)";
            // 
            // redRToolStripMenuItem
            // 
            this.redRToolStripMenuItem.Name = "redRToolStripMenuItem";
            this.redRToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.R)));
            this.redRToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.redRToolStripMenuItem.Text = "Red(&R)";
            this.redRToolStripMenuItem.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // blueBToolStripMenuItem
            // 
            this.blueBToolStripMenuItem.Name = "blueBToolStripMenuItem";
            this.blueBToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.B)));
            this.blueBToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.blueBToolStripMenuItem.Text = "Blue(&B)";
            this.blueBToolStripMenuItem.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // greenGToolStripMenuItem
            // 
            this.greenGToolStripMenuItem.Name = "greenGToolStripMenuItem";
            this.greenGToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.G)));
            this.greenGToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.greenGToolStripMenuItem.Text = "Green(&G)";
            this.greenGToolStripMenuItem.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // 색상선택SToolStripMenuItem
            // 
            this.색상선택SToolStripMenuItem.Name = "색상선택SToolStripMenuItem";
            this.색상선택SToolStripMenuItem.Size = new System.Drawing.Size(163, 22);
            this.색상선택SToolStripMenuItem.Text = "색상선택(&S)";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.redRToolStripMenuItem1,
            this.greenGToolStripMenuItem1,
            this.blueBToolStripMenuItem1,
            this.색상선택ToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(138, 92);
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // redRToolStripMenuItem1
            // 
            this.redRToolStripMenuItem1.Name = "redRToolStripMenuItem1";
            this.redRToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.redRToolStripMenuItem1.Text = "Red(&R)";
            this.redRToolStripMenuItem1.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // greenGToolStripMenuItem1
            // 
            this.greenGToolStripMenuItem1.Name = "greenGToolStripMenuItem1";
            this.greenGToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.greenGToolStripMenuItem1.Text = "Green(&G)";
            this.greenGToolStripMenuItem1.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // blueBToolStripMenuItem1
            // 
            this.blueBToolStripMenuItem1.Name = "blueBToolStripMenuItem1";
            this.blueBToolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.blueBToolStripMenuItem1.Text = "Blue(&B)";
            this.blueBToolStripMenuItem1.Click += new System.EventHandler(this.redRToolStripMenuItem_Click);
            // 
            // 색상선택ToolStripMenuItem
            // 
            this.색상선택ToolStripMenuItem.Name = "색상선택ToolStripMenuItem";
            this.색상선택ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.색상선택ToolStripMenuItem.Text = "색상선택(&S)";
            this.색상선택ToolStripMenuItem.Click += new System.EventHandler(this.색상선택ToolStripMenuItem_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripComboBox1});
            this.toolStrip1.Location = new System.Drawing.Point(0, 24);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 25);
            this.toolStrip1.TabIndex = 2;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton1.Image")));
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size(23, 22);
            this.toolStripButton1.Text = "toolStripButton1";
            this.toolStripButton1.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size(121, 25);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 428);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(800, 22);
            this.statusStrip1.TabIndex = 3;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(121, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.ContextMenuStrip = this.contextMenuStrip1;
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.contextMenuStrip1.ResumeLayout(false);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 파일FToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 프로그램종료XToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 팬색상PToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem redRToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem blueBToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem greenGToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 색상선택SToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem redRToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem greenGToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem blueBToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 색상선택ToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
    }
}

