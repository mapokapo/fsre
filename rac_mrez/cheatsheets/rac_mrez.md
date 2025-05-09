# Racunalne Mreze

- [\*] vazno, vjv ce bit na ispitu
- [x] pitanje se ponavlja vise od jednom na prezentacijama
- [?] ne znam treba li ucit

## 1. PREZENTACIJA

- [\*] informacijska mreza (transmisija, komutacija, procesiranje)
- fundamentalni problem komunikacije i procesiranja
- [\*] shannonova granica za kapacitet mreze/procesora
- [\*] komunikacijski model (terminal, cvor, grane)
- problem povezivanja korisnika
- [\*] kanali i paketi, premjestanje i usmjeravanje
- upravljacke i korisnicke informacije
- [\*] topologije (potpuna povezanost, zvijezda, prsten, sabirnica, stablo)
- [\*] fiksna telefonska mreza i internet
- inteligencija mreze
- [\*] mrezna arhitektura (slojevi + protokoli)
- [\*] OSI i TCP/IP modeli
- [x] prijenosni mediji (parice, coax. kabel, optika, radio, infracrveno)
- [\*] podjele mreza (po ustrojstvu, uporabi, podrucju, tehnologiji, vrsti informacije, i vrsti razasiljanja)
- [\*] unicast, broadcast, multicast
- arpanet, nsfnet, arhitektura interneta, ISO, ITU, IEEE, IETF
- [\*] kodiranje, ASCII
- baseband, broadband
- simplex, half duplex, full duplex
- paralelni, serijski, asinkroni, i sinkroni prijenos
- [\*] otkrivanje i otklanjanje gresaka (kontrola pariteta, LRC, CRC), ARQ
- efikasnost kodova i protokola (cestina, TRIB)
- AMI, manchester kod
- [\*] komunikacijski mediji (upletene parice (UTP, STP), coax. kabel (tanki i debeli), optika (multimodno i monomodno, disperzija, valni multipleks), bezicni prijenos (wifi, radio, mikrovalovi, infracrveni, sateliti)), gusenje

## 2. PREZENTACIJA

- [\*] sirina pojasa, harry nyquist formula
- [\*] de/modulatori, vrste modulacije (amplitudna, frekvencijska, fazna)
- [?] konstelacijski dijagram (QAM, V.32, V.34)
- DSL, DSLAM, POTS/PSTN (ista stvar), ISDN
- slabljenje (atenuacija), premosteni odvojnici (bridged taps), preslusavanje (crosstalk)
- [?] razne verzije xDSL (ADSL, VDSL, VDSL2, itd.)
- [\*] PCM (uzorkovanje, kvantiziranje, kodiranje), prednosti digitalnog prijenosa
- [\*] teorem uzoraka (isto kao H. Nyquist formula), PAM
- [?] kvantizacijski sum
- [?] nelinearno kvantiziranje, 13-segmentni A-zakon
- PDH, slijepi bit, nedostatci, SDH
- B-ISDN, ATM (celije od 53 okteta, BRA, PRA), B i D kanali, slojevi (fizikalni, ATM, AAL), korisnicka, kontrolna, i upravljacka ploha
- [?] mreze, UNI i NNI
- [?] kanali, GFC, VPI, VCI (PVC, SVC)
- [?] ispravljanje gresaka, PTI (CLP, HEC)
- [?] sinkronizacija, IDLE i OAM celije
- [?] CBR, VBR, ABR, UBR
- [\*] OSI i TCP/IP modeli, protokol-protokol (horizontalna) komunikacija (isti sloj)
- [\*] entitet, istorazinski entiteti, entiteti sloja n, pruzatelji/korisnici usluge (SAP, IDU, SDU, PDU)
- [\*] konekcijska i bezkonekcijska usluga, pouzdana i nepouzdana, potvrdjena i nepotvrdjena, usluga zahtjev-odgovor
- [\*] sekvenca poruka, struja okteta, datagram

## 3. PREZENTACIJA

- namjenski i komutirani krug
- DTE (oprema terminala podataka), DCE (oprema podatkovnog terminalnog kruga)
- [?] DTE->DCE vodici (G, Ga, Gb, T, R, C, I, S, B)
- [?] nul-modem
- tehnika uravnotezenog prijenosa
- [?] specifikacije kabela (RS-485, RS-232)
- USB
- sloj linka podataka
- kontrola gresaka (BEC, FEC)
- kontrola toka (SW tj. AB, GBN, SR)
- [\*] IP, SLIP, CSLIP
- [\*] PPP, komponente (okvir, LCP, NCP)
- [\*] centralizirani (polling) i distribuirani (token bus, token ring) sustavi
- [?] round robin
- natjecateljski, rezervacijski pristup (TDMA, FDMA, CDMA, WDMA)
- pure i slotted aloha
- [\*] CSMA (carrier sense multiple access), CD (collision detection)
- [\*] bit-map protokol (primjer rezervacijskog protokola), binary countdown
- [\*] LAN (LLC, MAC)
- [\*] Ethernet (IEEE 802.3), kolizija (binary expenontial backoff), specifikacije (topologija je sabirnica, nema modulacije, manchester kodiranje, RS-232)
- [?] komutirani ethernet (switch)
- [?] fast ethernet (802.3u, upletena parica - 100 base-t4 i 100 base-tx, opticki - 100 base-fx)
- [?] gigabit ethernet (802.3z, opticki - 1000 base-sx, 1000 base-lx, parice - 1000 base-cx, 1000 base-t)
- [?] 10 gigabit ethernet (802.ae, 10G base-S, 10G base-l, 10G base-e, 10G base-lx4, 10G base-t)
- [\*] prijenosnik (repeater), most (bridge), usmjeritelj (router), prospojnik (gateway)
- [\*] most (radi na sloju 1 i 2, povezuje LAN-ove iste vrste (npr. ne moze most biti izmedju ethernet i token ring), sluzi za filtriranje okvira, moze pohraniti okvire prije nego sto se posalju, nisu bas inteligentni no postoje protokoli koji to rijesavaju (STP), lokalni i udaljeni most) - danas se umjesto mostova koriste layer dva switchevi
- [\*] router (radi na 3. sloju, ima mogucnost kontrole prometa i usmjeravanja, stvara optimiziranu tablicu ruta kroz mrezu, dijele se na staticke i dinamicke) - danas se sve vise koriste layer tri switchevi
- [\*] gateway (omogucuje spajanje dvaju potpuno razlicitih LAN-ova (npr. ISO i TCP/IP model) tako sto implementira citav mrezni sloj za svaku od mreza)

## 4. PREZENTACIJA

- protokoli (nabrojati, transport: TCP, UDP, BGP, network: IP, ICMP, RIP, data link: ARP, RARP)
- IP adrese, klase, podmreze, besklasno adresiranje
- domene, DNS, FQDN, hijerarhija
- DHCP, usmjeritelji (nabrojati IGP (unutarnje) i EGP (vanjske) protokole), znati o RIP i OSPF
- poplavljivanje, staticki i dinamicki algoritmi
- MTU, IP fragmentacija
- ICMP, ping, traceroute
- ARP, RARP (danas se vise koriste DHCP i BOOTP)
- IPV6
