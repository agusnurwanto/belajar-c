#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main() {
    // Inisialisasi Winsock untuk Windows
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cerr << "WSAStartup gagal: " << iResult << endl;
        return 1;
    }

    // Membuat Socket untuk listen/menerima koneksi
    SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        cerr << "Error pembuatan socket: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    // Konfigurasi IP dan Port Server
    sockaddr_in serverService;
    serverService.sin_family = AF_INET;
    serverService.sin_addr.s_addr = INADDR_ANY; // Menerima koneksi dari semua interface
    serverService.sin_port = htons(8080); // Berjalan di port 8080

    // Binding socket ke local address dan port
    iResult = bind(ListenSocket, (SOCKADDR*)&serverService, sizeof(serverService));
    if (iResult == SOCKET_ERROR) {
        cerr << "Bind gagal: " << WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Memulai untuk mendengarkan koneksi yang masuk
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        cerr << "Listen gagal: " << WSAGetLastError() << endl;
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server sedang berjalan di http://localhost:8080" << endl;
    cout << "Tekan Ctrl+C untuk mematikan." << endl;

    // Loop utama untuk menerima koneksi (Connection loop)
    while (true) {
        SOCKET ClientSocket = accept(ListenSocket, NULL, NULL);
        if (ClientSocket == INVALID_SOCKET) {
            cerr << "Accept gagal: " << WSAGetLastError() << endl;
            continue;
        }

        // Menerima request dari browser/client
        char recvbuf[1024];
        iResult = recv(ClientSocket, recvbuf, sizeof(recvbuf), 0);

        if (iResult > 0) {
            // Null terminate the received buffer to treat it safely as string
            recvbuf[iResult] = '\0';
            
            // Header respon HTTP beserta body konten HTML-nya
            string response = 
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Connection: close\r\n"
                "\r\n"
                "<html>"
                "<head><title>Web Server C++</title><style>body{font-family: Arial; text-align: center; margin-top: 50px;}</style></head>"
                "<body>"
                "<h1>Halo Kawan! 🚀</h1>"
                "<p>Ini adalah web server yang dibuat dengan bahasa C++ murni menggunakan Winsock API.</p>"
                "</body>"
                "</html>";
            
            // Mengirim respon ke client (browser)
            send(ClientSocket, response.c_str(), response.length(), 0);
        }

        // Tutup koneksi agar browser selesai me-load halaman
        closesocket(ClientSocket);
    }

    // Bersihkan sebelum keluar
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}
