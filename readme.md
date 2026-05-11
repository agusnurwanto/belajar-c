# Belajar C++ - Program Web Server Sederhana

Proyek ini adalah contoh sederhana pemrograman dasar menggunakan bahasa C++. Di dalam direktori ini, terdapat dua buah program yang dapat Anda pelajari dan uji coba jalankan secara langsung:

1. **`halokawan.cpp`**: Program konsol dasar *Hello World*.
2. **`web_server.cpp`**: Program Web Server sederhana yang berjalan di port `8080` dan mendemonstrasikan fungsionalitas jaringan antarmuka *Sockets* pada Windows (menggunakan `Winsock2`) untuk mengirim pembalasan *(response)* kepada peramban *(browser)* secara langsung.

---

## 🛠 Panduan Kompilasi & Menjalankan Code

Anda dapat merubah kode `.cpp` menjadi sebuah file *Executable* (`.exe`) yang bisa dijalankan di Windows dengan instruksi berikut, tergantung *compiler* mana yang sudah Anda miliki di OS Anda:

### 1. Menggunakan compiler `g++` (MinGW / GCC)
Jika Anda menggunakan sistem compiler terbuka seperti **MinGW** (biasanya di-*bundle* oleh aplikasi DevC++, MSYS2, atau instalasi ekstensi VS Code), maka saat membangun `web_server.cpp` Anda **wajib menautkan flag library winsock** (`-lws2_32`).

Buka Terminal / CMD di dalam folder ini lalu jalankan:

**Kompilasi Web Server:**
```cmd
g++ web_server.cpp -o web_server.exe -lws2_32
```

**Kompilasi Halo Kawan:**
```cmd
g++ halokawan.cpp -o halokawan.exe
```

### 2. Menggunakan Microsoft MSVC (`cl.exe` Visual Studio)
Pastikan Anda membuka **Developer Command Prompt for VS** atau men-setup env CLI Anda agar sistem dapat menemukan perintah `cl`. Karena pada bagian *source code* kita sudah menggunakan baris `#pragma comment(lib, "Ws2_32.lib")`, Anda tidak perlu lagi mendefinisikan library ini sewaktu proses kompilasi.

**Kompilasi Web Server:**
```cmd
cl web_server.cpp
```

**Kompilasi Halo Kawan:**
```cmd
cl halokawan.cpp
```

---

## 🚀 Pengujian Web Server
Setelah Anda mendapati file bereksistensi `.exe` rampung terbentuk pada folder (misalnya `web_server.exe`), maka Anda cukup mengeksekusi berkas tersebut layaknya sebuah server:

1. Ketik perintah berikut pada cmd/terminal Anda:
   ```cmd
   .\web_server.exe
   ```
2. Aplikasi akan terblok dan mencetak baris:
   `Server sedang berjalan di http://localhost:8080`
3. Silakan beralih ke aplikasi peramban / browser Andalan Anda (Chrome/Firefox/Edge).
4. Akses URL berikut pada bar alamat URL browser Anda:  
   👉 **http://localhost:8080/**
5. Selamat! Browser kini akan merender laman web sederhana yang Anda kirim via script C++ tersebut.
6. Untuk mematikan server, buka jenedala terminal kembali lalu tekan tombol **`Ctrl + C`**.
