
# Cub3D

Cub3D, Wolfenstein 3D benzeri bir 3D raycasting motoru geliştirme projesidir. Bu proje, basit bir FPS tarzı oyunun temel yapı taşlarını içeren bir raycasting motoru sağlar. Proje, 42 okullarındaki Cub3D projesi kapsamında geliştirilmiştir.

## İçindekiler
- [Özellikler](#özellikler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Proje Yapısı](#proje-yapısı)


## Özellikler
- 2D harita üzerinden 3D dünya oluşturma.
- Basit düşman yapay zekası.
- Duvarlara, kapılara ve oyuncuya özgü dokular.
- FPS mekanikleri: hareket etme, zıplama, eğilme.
- Klavye ve fare desteği.
- Linux ve macOS uyumlu.

## Kurulum

### Gereksinimler
- C kütüphaneleri (GCC/Clang)
- Makefile
- MinilibX

### Derleme
Projeyi yerel makinenize klonlayın:
```bash
git clone https://github.com/TufanKurukaya/Cub3D.git
```

Daha sonra, proje dizininde şu komutu çalıştırarak derleyin:
```bash
make
```

## Kullanım
Derlemeden sonra oyunu başlatmak için:
```bash
./cub3D [harita_dosyasi]
```
Örnek olarak:
```bash
./cub3D maps/level1.cub
```

### Oyun İçi Kontroller
- W/A/S/D: Hareket etme
- Fare: Etrafı görme
- ESC: Oyunu kapatma

## Proje Yapısı
```
Cub3D/
├── srcs/          # Kaynak kodlar
├── includes/      # Başlık dosyaları
├── maps/          # Oyun haritaları
├── textures/      # Dokular
└── Makefile       # Derleme dosyası
```
