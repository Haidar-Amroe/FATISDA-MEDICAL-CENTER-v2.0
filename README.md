# 🏥 FATISDA Medical Center Management System V2.0
FATISDA Medical Center V2.0 adalah pembaruan besar dari sistem manajemen pasien sebelumnya. Versi ini beralih dari penggunaan Array statis ke Linked List (Senarai Berantai) yang memungkinkan penyimpanan data pasien secara dinamis tanpa batas jumlah tetap. Selain itu, versi ini dilengkapi dengan fitur penyimpanan file (database .txt), algoritma pencarian rekursif, dan antarmuka animasi yang lebih interaktif.

# ✨ Fitur Utama
Program ini menawarkan peningkatan fitur yang signifikan dibandingkan versi sebelumnya:

1. Manajemen Data Dinamis (Linked List) 🔗
Tidak ada lagi batasan jumlah pasien (seperti batas 100 pada versi array).
Menggunakan alokasi memori dinamis (malloc) dan struktur struct dataPasien *next untuk fleksibilitas data .


2. Penyimpanan Data Permanen (File Handling) 💾
Auto-Load: Data pasien lama akan dimuat otomatis dari file data pasien.txt saat program dijalankan.
Auto-Save: Data pasien baru akan disimpan secara permanen ke dalam file saat pengguna memilih menu keluar.

3. Algoritma Pencarian Rekursif 🔍
Mengimplementasikan fungsi rekursif cariRekursif untuk menelusuri Linked List saat mencari ID pasien, menggantikan metode iterasi standar.

4. Analisis Kesehatan Otomatis 🩺
Cek Kondisi Klinis: Mendiagnosa kondisi pasien (Normal, Demam, Hipotermia, Darurat) berdasarkan input suhu tubuh.
Kalkulator BBI (Broca): Menghitung Berat Badan Ideal sesuai jenis kelamin dan memberikan status berat badan (Ideal/Kurang/Berlebih).

5. Statistik & Pelaporan 📊
Statistik Umur: Menghitung rata-rata umur seluruh pasien yang terdaftar.
Rekap Kondisi: Menampilkan jumlah total pasien berdasarkan kategori kesehatan (Aman, Demam, Darurat).

6. Antarmuka Interaktif (UI/UX) 🎨
Animasi Teks: Menggunakan fungsi typeAnimation untuk memberikan efek pengetikan yang halus pada intro dan menu.
ASCII Art: Menampilkan logo FATISDA MEDICAL yang menarik secara visual.
