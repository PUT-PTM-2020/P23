<h1 align="center">
  <img src="Logo.png" width="200">
  <br>
  Terminal / Bankomat
  <br>
</h1>

<h4 align="center">Wykorzystano STM32, RFID, WiFi </h4>

<p align="center">
  <a href="#">Iza Błażejewicz</a> •
  <a href="#">Dominik Adamek</a> •
  <a href="#">Maciej Chajda</a>
</p>

<p align="center">
<img  src="Web/mockup2.png">
</p>

## Kluczowa funkcjonalność

### STM
* Doładowanie salda
  - Użytkownik po przyłożeniu karty do terminalu wpisuje na klawiaturze kwotę o jaką jego konto zostanie zasilone.
* Przelew między kontami
  - Wprowadzamy kwotę do przelania między kontami, następnie przykładamy dwie karty, jedna po drugiej, a transakcja zostanie wykonana
  - (Opcjonalnie) wpisujemy numer Id konta na które chcemy przelać kwotę
* Główna część logiczna
  - bezpośrednia odpowiedzialność za zgodność i poprawność transakcji
  
### Cloud
* Interfejs webowy
  - Podgląd kont oraz ich salda
* Storage
  - Przechowuje wszystkie dane związane z kontami

# Dokumentacja techniczna
* *UserId* - zmienna identyfikująca użytkownika
* *Balance* - saldo użytkownika
* *char* - pojedynczy znak wysłany z klawiatury numerycznej
* *text* - komunikat wysłany z STM do użytkownika 

| STM <> WiFi | Funkcja | Zwraca | WiFi <> Chmura |
|-------------------------------|-----------------------------------------|--------------------------------|------------------------------------------|
| getBalance:*UserId* | Pobiera saldo użytkownika | **float** reprezentujący saldo | https://____/api/getSaldo/UserId |
| setBalance:*UserId*:*Balance* | Zapisuje saldo użytkownika na serwerze | **void** | https://____/api/setSaldo/UserId/Balance |
| input:*char* | Wysyła informację o wciśniętym klawiszu | **void** |  |
| showMessage:*text* | Wysyła komunikat do użytkownika | **void** |  |
