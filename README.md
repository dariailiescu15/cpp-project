# cpp-project
Acest proiect reprezintă o aplicație C++ structurată sub forma unui meniu interactiv, care permite utilizatorului să acceseze și să testeze o serie de algoritmi fundamentali studiați în cadrul cursului de Algoritmi și Structuri de Date. Programul este modular, fiecare cerință fiind implementată prin funcții dedicate, iar meniul principal oferă acces rapid la toate operațiile.

Proiectul include următoarele funcționalități:

## 1. Ordonarea unui șir de caractere
Implementare simplă de sortare alfabetică folosind comparații directe și interschimbări.
Exemplu din cod: „if(c[i]>c[j]) { char aux = c[i]; ... }”.

## 2. Ordonarea unui șir de cuvinte
Sortare lexicografică a unui vector de string‑uri folosind comparații între cuvinte.

## 3. Sortarea unui șir de numere întregi folosind algoritmul Radix
Implementare completă a algoritmului Radix Sort folosind cozi pentru distribuirea elementelor pe cifre.
Codul definește o structură de coadă și operațiile push, pop, verif_null.

## 4. Interclasarea a n liste simplu înlănțuite
Citire, afișare și interclasare recursivă a listelor ordonate.
Funcția interclasare_n combină succesiv toate listele.

## 5. Liste circulare simplu înlănțuite
Creare, afișare, adăugare, ștergere și modificare într‑o listă circulară.
Fragment din cod: „do { cout << p->info << " "; p = p->next; } while (p != cap);”.

## 6. Reuniunea și intersecția a două mulțimi reprezentate prin liste dinamice
Inserare ordonată fără duplicate, apoi calculul reuniunii și intersecției prin parcurgere simultană.

## 7. Arbori binari – reprezentare și parcurgeri (RSD, SRD, SDR)
Construirea arborelui pe baza perechilor părinte‑copil și implementarea celor trei parcurgeri clasice.

## 8. Arbori binari de căutare (ABC)
Operații complete: inserare, ștergere, modificare nod, plus parcurgere în ordine (SRD).

## 🎯 Scopul proiectului
Proiectul demonstrează înțelegerea și implementarea practică a unor structuri de date fundamentale (liste, cozi, arbori) și a unor algoritmi esențiali (sortări, interclasări, Radix, operații pe arbori). Meniul interactiv permite testarea facilă a fiecărei funcționalități, ceea ce îl face util atât pentru învățare, cât și pentru evaluare.

## © 2024 — Project created by Iliescu Daria.
All rights reserved. Use, distribution, or modification of this code or associated materials is permitted only with proper attribution to the author.
