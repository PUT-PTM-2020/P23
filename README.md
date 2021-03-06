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
<img  src="mockup2.png">
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
## Komunikaty wymieniane między STM, a modułem WiFi

| STM <> ESP | Opis |
|-|-|
| GetLastId | Zwraca ostatnio odczytane Id, "null" jeśli pusty |
| ClearLastId | Czyści bufor skanera Id |
| GetHttpRequest:*URL* | Pobiera zawartość podanego URL |
