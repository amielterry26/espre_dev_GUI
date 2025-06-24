# 🖥️ Qt GUI App Deployment on Ubuntu EC2 with Cinnamon + xRDP

This guide documents the complete, working setup for running a C++ Qt-based GUI app on a remote Ubuntu EC2 instance with Cinnamon desktop and xRDP — fully accessible via Remote Desktop from any machine.

---

## 📦 Requirements

- Local development machine (Mac recommended)
- A Qt-based GUI repo (e.g. `rfsom-box-gui`)
- SSH keypair for EC2 access
- AWS account with access to launch EC2 instances
- Remote Desktop client (Microsoft Remote Desktop)

---

## 🚀 Step-by-Step Setup

---

### 1. 🧰 Clone the Repository Locally (Mac)

On your Mac:

```bash
git clone https://github.com/amielterry26/rfsom-box-gui.git
```

(If this fails, download ZIP from GitHub → extract to a local folder)

---

### 2. 🔐 Launch Ubuntu EC2 Instance

On AWS:
- Choose **Ubuntu 22.04 LTS** or **24.04 LTS**
- Instance type: `t2.medium` or better
- Allow inbound **port 3389** for RDP (in Security Group)
- Download or use an existing key pair (`.pem`)

---

### 3. 🌐 SSH into the EC2 Instance

```bash
ssh -i ~/path/to/keypair.pem ubuntu@<your-ec2-ip>
```

---

### 4. 🧱 Update + Install Cinnamon Desktop + xRDP

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install -y cinnamon-desktop-environment xrdp xserver-xorg-video-dummy
sudo systemctl enable xrdp
```

---

### 5. 🖼️ Set Default GUI Session

```bash
echo "cinnamon-session" > ~/.xsession
chmod +x ~/.xsession
```

---

### 6. 🔑 Set a Password for RDP Login

```bash
passwd ubuntu
```

(You’ll use this in your RDP client)

---

### 7. 🔁 Restart GUI Services

```bash
sudo systemctl restart xrdp
sudo systemctl restart xrdp-sesman
```

---

### 8. 💻 Connect via Remote Desktop

Open **Microsoft Remote Desktop** and connect to:

- IP: `<your-ec2-ip>`
- User: `ubuntu`
- Password: (from above)

You should now see a Cinnamon desktop GUI.

---

### 9. 🚚 Transfer the GUI Project to Server

From your **Mac**, run:

```bash
scp -i ~/path/to/keypair.pem -r ~/path/to/rfsom-box-gui ubuntu@<your-ec2-ip>:/home/ubuntu/
```

---

### 10. 🛠️ Build the Qt Project

SSH into the server again:

```bash
ssh -i ~/path/to/keypair.pem ubuntu@<your-ec2-ip>
```

Then build:

```bash
cd ~/rfsom-box-gui
mkdir build_packrf
cd build_packrf
sudo apt install -y qt5-qmake qtbase5-dev
qmake ..
make
```

---

### 11. 🎯 Launch the GUI App

Still inside the RDP session’s terminal:

```bash
cd ~/rfsom-box-gui/build_packrf
./rfsom-box-gui
```

✅ It should launch the full Qt GUI **inside your RDP desktop**.  
You do **not** need `DISPLAY=:10` unless it fails — but in our case, it worked without it.

---

## 🔄 Repeat Notes

- Always make sure `.xsession` is set and executable.
- The RDP GUI session must be launched with a valid password (`passwd ubuntu`).
- If Qt fails to build, verify `.pro` file exists and `qmake` is installed.
- If app doesn’t launch, check logs via `journalctl` or `~/.xsession-errors`.

---

## ✅ Confirmed Working Environment

- Ubuntu 22.04 LTS (EC2)
- Cinnamon Desktop + xRDP
- Qt GUI project using `qmake` + `make`
- Remote Desktop access from macOS

---

## Author

Crafted with precision by 🧙🏾‍♂️ [Amiel Terry](https://amielterry.me) & Arcane Systems LLC