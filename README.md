# `get_next_line`

Bu proje, bir dosya tanımlayıcısından (`file descriptor`) her çağrıldığında bir sonraki satırı okuyan bir C fonksiyonu olan `get_next_line`'ı uygulamanı sağlar. Dosya okuma işlemleri genellikle satır bazında yapılır ve bu fonksiyon, bu tür senaryolarda oldukça kullanışlıdır.

## Genel Bakış

`get_next_line` fonksiyonu, bir dosyadan okuma yaparken, her çağrıldığında yeni bir satır (yeni satır karakteri `'\n'` ile biten veya dosyanın sonuna kadar olan kısım) döndürür. Bu, büyük dosyaları okurken veya akış halindeki verileri işlerken bellek verimliliği sağlamak için önemlidir.

Fonksiyon, bir satırı okurken, bir sonraki okuma için kalan verileri statik bir değişken aracılığıyla saklamaktadır. Bu sayede, aynı dosya tanımlayıcısına yapılan sonraki çağrılar, kaldığı yerden okumaya devam edebilir.
