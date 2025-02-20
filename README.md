# Syslog-Access-Helper(Syslog-Erişim-yardımcısı)

Bu proje, Linux işletim sisteminde bulunan syslog günlüklerini okuyarak bağlı liste (linked list) veri yapısı ile saklamaya ve filtrelemeye yardımcı olur. Kullanıcılar belirli anahtar kelimeler girerek sadece ilgilendikleri log mesajlarını görüntüleyebilir.

🚀 Özellikler

Syslog dosyasını okur ve bağlı listeye kaydeder.

Dinamik bellek kullanımı ile sistem kaynaklarını verimli kullanır.

Anahtar kelimeye göre filtreleme ile log verilerini analiz eder.

Tek yönlü bağlı liste (Singly Linked List) veri yapısını kullanarak logları saklar.

🔧 Kurulum

Projeyi çalıştırmak için aşağıdaki adımları takip edin.

1. Depoyu Klonlayın

git clone https://github.com/kullanici/syslog-linked-list.git
cd syslog-linked-list

2. Syslog'u İndirin ve Yükleyin

Bazı Linux dağıtımlarında syslog varsayılan olarak yüklü gelmeyebilir. Eğer sisteminizde rsyslog bulunmuyorsa, aşağıdaki komutlarla yükleyebilirsiniz:

sudo apt update && sudo apt install rsyslog -y  # Debian/Ubuntu tabanlı sistemler
sudo yum install rsyslog -y                     # CentOS/RHEL tabanlı sistemler
sudo dnf install rsyslog -y                     # Fedora için

3. Syslog'u Etkinleştirin

Linux sisteminizde syslog hizmetinin aktif olduğundan emin olun.

sudo systemctl start rsyslog
sudo systemctl enable rsyslog

4. Projeyi Derleyin

Projeyi derlemek için bir C derleyicisine ihtiyacınız vardır. Linux sistemlerinde yaygın olarak kullanılan bazı C derleyicileri şunlardır:

GCC (GNU Compiler Collection) → En yaygın kullanılan açık kaynaklı derleyici.

Clang → LLVM tabanlı optimize edilmiş bir derleyici.

TinyCC (TCC) → Hafif ve hızlı bir C derleyicisi.

ICC (Intel C Compiler) → Intel işlemciler için optimize edilmiş bir derleyici.

Ayrıca, projeyi daha rahat bir geliştirme ortamında çalıştırmak için aşağıdaki entegre geliştirme ortamlarını (IDE) kullanabilirsiniz:

CLion → JetBrains tarafından geliştirilen güçlü bir C/C++ geliştirme ortamı.

Visual Studio → Microsoft tarafından sağlanan kapsamlı bir IDE; özellikle Windows ortamında geliştirme yapıyorsanız faydalıdır.

Projeyi derlemek için aşağıdaki komutu çalıştırabilirsiniz:

gcc -o syslog_parser syslog_parser.c

5. Uygulamayı Çalıştırın

./syslog_parser

📌 Kullanım

Program çalıştırıldığında syslog dosyasını okur.

Kullanıcıdan anahtar kelime girmesi istenir.

Girilen kelimeye uygun log mesajları ekrana yazdırılır.

Örnek Kullanım

Filtrelemek istediğiniz anahtar kelimeyi girin: ssh

Anahtar kelimeye göre filtrelenen loglar:
Feb 14 12:34:56 server1 sshd[1234]: Accepted password for user from 192.168.1.10

📝 Kod Açıklamaları

LogDugum** Yapısı** → Tek yönlü bağlı listedeki her düğüm bir log mesajı içerir.

dugumEkle() → Yeni log mesajlarını bağlı listeye ekler.

logFiltrele() → Girilen anahtar kelimeye göre logları filtreler.

listeTemizle() → Bellekte tutulan bağlı listeyi temizler.

📊 Alternatif Senaryolar

Çift yönlü bağlı liste (Doubly Linked List) kullanımı: Eğer logları daha verimli gezmek ve silme işlemlerini kolaylaştırmak isterseniz çift yönlü bağlı liste kullanılabilir.

Kuyruk (Queue) yapısı: Gerçek zamanlı log izleme işlemleri için bağlı liste yerine kuyruk yapısı kullanılabilir.

Ağaç veri yapıları: Daha hızlı arama işlemleri için AVL Ağacı veya B+ Ağacı kullanılabilir.

🎯 Katkıda Bulunma

Projeye katkı sağlamak isterseniz, pull request açabilir veya bir issue oluşturabilirsiniz.

📜 Lisans

**Herkes tarafından serbestçe kullanılabilir, değiştirilebilir ve dağıtılabilir. Ancak, projeyi kullanırken **orijinal yazara kredi verilmesi ve sadece kendi eseri gibi sunulmaması gerekmektedir.

Hazırlayan: Batuhan Toker
Daha fazla bilgi için www.linkedin.com/in/batuhan-toker-83134b32b /---/ https://github.com/ba2han1 📌
