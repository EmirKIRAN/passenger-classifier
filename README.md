# Yolcu Sınıflandırma Uygulaması

Tren yolculukları için kesilen biletlerin, üzerinde bulunan illere göre sıralı ve düzenli bir biçimde sınıflandırılmasını sağlayan C++ dilinde yazılmış bir uygulamadır.



## Giriş

Kullanıcı tarafından verilen bir girdi dosyasındaki (passengerList.txt) yolcu bilgilerine göre yolcuları varacakları hedef noktaya göre sınıflandırıp illere göre çıktı dosyası oluşturan bir C++ projesidir.

Kullanıcılar giriş dosyasına:

````c++
isim<space>soyisim<space>varis_noktasi
````

biçiminde ekledikleri yolcular için sınıflandırma işlemi yapılmaktadır. Şu an için üç il bazında sınıflandırma yapan uygulama girdi olarak verilen iller dahilinde çıktı dosyası üreterek yolcuları bu dosyalara yerleştirir.

Kullanıcıların bu uygulamayı kullanabilmesi için şu kodları projesine dahil etmektir:

````c++
#include <iostream>
#include <TicketClassifier.h>

using namespace std;


int main()
{
    TicketClassifier tc("passengerList.txt"); // here it is sufficient to simply indicate the location of the file containing    passengers' information.
    tc.getInstance(); // this method that creates files.
}
````

<b>TicketClassifier</b> sınıfı ile bir nesne oluşturarak kurucu metoda girdi dosyasını vermeleri yeterlidir. Daha sonrasında <b>getInstance()</b> metodunu çağırarak sınıflandırma işlemini gerçekleştirebilirler.

Bu proje <b style="color:#7B7AE3;">Factory Tasarım Deseni</b> ile yapıldığından dolayı daha fazla il çok kolay bir biçimde türetilebilmektedir. Projeyi geliştirmek isteyenler için şu şekilde anlatabiliriz:

> * Yeni oluşturmak istediğiniz il için bir sınıf oluşturun.
>
> * Oluşturduğunuz sınıf,  <b>"City"</b> sınıfından türetilmelidir(inheritance) . <b>"City"</b> sınıfı bir soyut(abstract) sınıf olduğu için sınıfa ait metotları gerçeklemeniz gerekmektedir(implementation).
> * Diğer sınıflarda olduğu gibi metotları gerçekleştirdikten sonra factory sınıfına giderek yeni oluşturmuş olduğunuz sınıfı oluşturmasını sağlamalısınız.
> * Son olarak girdi dosyasına oluşturduğunuz ile ait bir yolcu kaydı eklemelisiniz.



## Notlar

<svg style="color:#FFE484;margin-bottom:-5px;margin-right:15px;" xmlns="http://www.w3.org/2000/svg" width="26" height="26" fill="currentColor" class="bi bi-exclamation-triangle-fill" viewBox="0 0 16 16">
  <path d="M8.982 1.566a1.13 1.13 0 0 0-1.96 0L.165 13.233c-.457.778.091 1.767.98 1.767h13.713c.889 0 1.438-.99.98-1.767L8.982 1.566zM8 5c.535 0 .954.462.9.995l-.35 3.507a.552.552 0 0 1-1.1 0L7.1 5.995A.905.905 0 0 1 8 5zm.002 6a1 1 0 1 1 0 2 1 1 0 0 1 0-2z"/>
</svg> Proje CodeBlocks üzerinden direkt olarak <b>train_station.cbp</b> dosyasının çalıştırılması ile hiçbir değişiklik yapmaya gerek kalmadan çalıştırılabilir.

<svg style="color:#FFE484;margin-bottom:-5px;margin-right:15px;" xmlns="http://www.w3.org/2000/svg" width="26" height="26" fill="currentColor" class="bi bi-exclamation-triangle-fill" viewBox="0 0 16 16">
  <path d="M8.982 1.566a1.13 1.13 0 0 0-1.96 0L.165 13.233c-.457.778.091 1.767.98 1.767h13.713c.889 0 1.438-.99.98-1.767L8.982 1.566zM8 5c.535 0 .954.462.9.995l-.35 3.507a.552.552 0 0 1-1.1 0L7.1 5.995A.905.905 0 0 1 8 5zm.002 6a1 1 0 1 1 0 2 1 1 0 0 1 0-2z"/>
</svg> Farklı IDE kullanan kullanıcılar ise <b>src</b> ve <b>include</b> dosyaları altında bulunan .cpp ve .h başlıklı dosyaları kullanarak projeyi çalıştırabilir.

<svg style="color:green;margin-bottom:-5px;margin-right:15px;" xmlns="http://www.w3.org/2000/svg" width="22" height="22" fill="currentColor" class="bi bi-check-circle-fill" viewBox="0 0 16 16">
  <path d="M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0zm-3.97-3.03a.75.75 0 0 0-1.08.022L7.477 9.417 5.384 7.323a.75.75 0 0 0-1.06 1.06L6.97 11.03a.75.75 0 0 0 1.079-.02l3.992-4.99a.75.75 0 0 0-.01-1.05z"/>
</svg> Bu projenin amacı Veri Yapılarını dinamik olarak kullanabilmek ve problemler üzerinde Tasarım Desenlerini doğru bir şekilde uygulayabilmektir.

<svg style="color:#17A2B8;margin-bottom:-5px;margin-right:15px;" xmlns="http://www.w3.org/2000/svg" width="26" height="26" fill="currentColor" class="bi bi-bookmark-star-fill" viewBox="0 0 16 16">
  <path fill-rule="evenodd" d="M2 15.5V2a2 2 0 0 1 2-2h8a2 2 0 0 1 2 2v13.5a.5.5 0 0 1-.74.439L8 13.069l-5.26 2.87A.5.5 0 0 1 2 15.5zM8.16 4.1a.178.178 0 0 0-.32 0l-.634 1.285a.178.178 0 0 1-.134.098l-1.42.206a.178.178 0 0 0-.098.303L6.58 6.993c.042.041.061.1.051.158L6.39 8.565a.178.178 0 0 0 .258.187l1.27-.668a.178.178 0 0 1 .165 0l1.27.668a.178.178 0 0 0 .257-.187L9.368 7.15a.178.178 0 0 1 .05-.158l1.028-1.001a.178.178 0 0 0-.098-.303l-1.42-.206a.178.178 0 0 1-.134-.098L8.16 4.1z"/>
</svg> Proje her türlü alanda düzenlenip geliştirilebilinir. Örneğin illere göre nöbetçi eczanelerin sınıflandırılması gibi.



## Yazarlar

Emirhan KIRAN - [Linkedin](https://www.linkedin.com/in/emir-kiran/)







