# 🔐 SSH Key Setup Guide – Connect to a Remote Linux Server Without Passwords

This guide walks you through generating an SSH key pair, uploading the public key to a remote Linux server, and logging in **without typing a password every time**.

> ⚠️ This guide uses placeholder values.  
> Replace with your actual server details (provided via encrypted email or secure channel).

---

## 📍 Step 1: Go to Your Working Directory

Choose any safe directory where you want to store your SSH keys. Example:

```bash
cd /home/yourusername/ssh_keys/
```

---

## 🔧 Step 2: Generate a New SSH Key Pair

This creates both a **private key** and a **public key**. When prompted for a passphrase, just press Enter (leave it empty) to avoid needing one.

```bash
ssh-keygen -t rsa -b 4096 -f your_custom_key_name
```

📁 This creates:
- `your_custom_key_name` → Private key (KEEP THIS SAFE)
- `your_custom_key_name.pub` → Public key (TO BE UPLOADED)

> 📌 You can name the key anything you want, like `server1_key` or `vpn_dev_key`.

---

## 📤 Step 3: Upload the Public Key to the Remote Server

Use this command to push the public key to the server.

```bash
ssh-copy-id -i your_custom_key_name.pub username@your.remote.ip.address
```

- `your_custom_key_name.pub` → The public key file you just created
- `username@your.remote.ip.address` → Replace with the actual server login credentials

🧠 Example:
If your server is `192.168.1.25` and your username is `ubuntu`, the command becomes:

```bash
ssh-copy-id -i server1_key.pub ubuntu@192.168.1.25
```

> 🔒 You may be asked for the **server password one time**. After this step, you'll no longer need it.

---

## 🔑 Step 4: Connect to the Server Using the Private Key

Now that the server trusts your key, you can log in like this:

```bash
ssh -i your_custom_key_name username@your.remote.ip.address
```

🧠 Example:
```bash
ssh -i server1_key ubuntu@192.168.1.25
```

You should be logged in with **no password or passphrase**.

---

## 💬 What Does `username@your.remote.ip.address` Mean?

- `username` = The Linux user on the remote server (e.g., `ubuntu`, `bitnami`, `ec2-user`, or `root`)
- `your.remote.ip.address` = The IP address of the remote server

💡 **Common users:**
| Server Type      | Login Username |
|------------------|----------------|
| Ubuntu Server    | `ubuntu`       |
| Bitnami Stack    | `bitnami`      |
| EC2 (Amazon)     | `ec2-user`     |
| Baremetal/Dedicated | `root`     |

> Use the correct user that matches the server setup. This info will be sent via secure email if unsure.

---

## 🧠 Final Summary

| What You Did                  | File Used                 | Purpose                         |
|-------------------------------|---------------------------|----------------------------------|
| Created SSH key               | `your_custom_key_name`    | Authenticate to the server       |
| Uploaded public key to server | `your_custom_key_name.pub`| Let the server recognize you     |
| Connected via private key     | `ssh -i your_key`         | Passwordless login               |

---

## 🚨 Important Security Notes

- Never share or upload your **private key** (`your_custom_key_name`)
- Only the `.pub` file should be sent to or installed on the server
- Store private keys in a secure folder with permission `chmod 600`

---

Crafted with clarity and security by 🧙🏾‍♂️ [Amiel Terry](https://amielterry.me) & Arcane Systems LLC