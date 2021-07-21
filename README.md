# opengl-glutLibrary


Q: Construct a 3D home and apply translation, rotatin and scaling transformations interactively. (use keyboard keys to transform)
You will use OPENGL and GLUT library.
3.3-)ÖlçeklendirmeVideo Link
https://www.youtube.com/watch?v=wD9bmU6UqM0
Kullanım Açıklamaları 
Kodumu ubuntu işletim sistemi üzerinden makefile kullanarak yaptım. Terminalde make ile beraber 
compile ve run işlemi gerçekleşiyor.
İşlevlerimin harf karşılıkları;
w--> +y
s--> -y 
a--> -x
d--> +x
f--> -z
g-->+z düzlemlerinde yer değişim sağlar
r--> döndürme işlemi sağlar her basışta bir birim döner uzun basımda süreklilik vardır
q--> bir birim küçültme işlevi sağlar
e--> bir birim büyültme işlevi sağlar.
Kodumda neler yaptım ve bunları nasıl gerçekleştirdim.
Yer değiştirme: evi x,y,z koordinat düzleminde hareket ettirme;
a ve d harfleri x düzleminde
w ve s harfleri y düzleminde
f ve g harfleri z düzleminde haraket ettirir.
 glutKeyboardFunc(handleKeypress); fonksiyonu glut kütüphanesine aittir, handleKeypress 
fonksiyonunu implement ederek klavyedeki tuşlara bu fonksiyonda bir görev veriyoruz.
Glabal olarak tanımladığım x,y,z değişkenlerine bu tuş kombinasyonları ile yeni değerler atamış 
oluyorum.
 else if (key=='g') {
 cout<<"z ekseni +++"<<endl;
 z+= 0.1f;
 glutPostRedisplay();
 }
glTranslatef(x,y,z); drawScene fonksiyonu içinde glut kütüphanesine ait fonksiyondur.
Evimin yer değişim işlevini görür.
bu değerleri atadıktan sonra glut kütüphanesinin glutPostRedisplay(); fonksiyonu ile evimi gösterimini 
tekrardan gerçekleştiriyorum.
Main fonksiyonumda bulunanan Glut kütüphanesin glutMainLoop(); fonksiyonu programımı kapatana 
kadar sürekli olarak değişen ev çizimimi otomatik olarak göstermemi sağlıyor.
GlutMainLoop() ve glutKeyboardFunc(handleKeypress) fonksiyonları ile düzenlediğim sistemi 
döndürme ve ölçeklendirme işlevlerimde de kullanıyorum.Döndürme işlemi:
Döndürme işlevini handleKeypress te r tuşu ile sağladım.
HandleKeypress
***
else if (key=='r') {
 cout<<"Rotate"<<endl;
 update();
 }
***
void update() {
 _angle += 1.0f;
 if (_angle > 360) {
 _angle -= 360;
 }
 glutPostRedisplay();
 
}
_angle global değişkenimdir, r tuşuna her basışta kaç birim dönme işlemi yapıcağını belirler.
 glRotatef(_angle, 0.0f, 1.0f, 0.0f); drawScene fonksiyonu içinde. GlRotatef glut kütüphanesi 
fonksiyonudur ve döndürme işlevini sağlar.
Ölçeklendirme işlemi: q ve e harfleri ile gerçekleşir.
 HandleKeypress{
***
else if (key=='e') {
 cout<<"scale +++"<<endl;
 scale=scale+0.1f;
 glutPostRedisplay();
 }
***
}
scale global değişkendir. Ölçek boyut bilgisini tutar.glutPostRedisplay() yeniden gösterim sağlar.
glScalef(scale,scale,scale); glut kütüphanesi işlevidir drawScene fonksiyonumun içinde evimin 
ölçeklenmesini sağlar.
