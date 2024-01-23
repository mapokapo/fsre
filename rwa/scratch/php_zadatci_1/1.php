<?php
// klasa koja opisuje koncept studenta i 2 atributa (public private protected)

class Ispit {
    private int $ocjena;
    
    public function __construct(int $ocjena) {
        $this->ocjena = $ocjena;
    }
    
    public function getOcjena() {
        return $this->ocjena;
    }
    
}

class Student {
    public String $imePrezime;
    protected String $tip = "Redovan";
    private int $brojPolozenihIspita = 0;
    
    public function __construct($imePrezime) {
        $this->imePrezime = $imePrezime;
    }
    
    public function dodajIspit($ispit) {
        if ($ispit->getOcjena() >= 2) {
            $this->brojPolozenihIspita += 1;
        }
    }
    
    public function dobijBrojPolozenihIspita() {
        return $this->brojPolozenihIspita;
    }
}

class IzvanredanStudent extends Student {
    public function __construct($imePrezime) {
        parent::__construct($imePrezime);
        
        $this->tip = "Izvanredan";
    }
}

$i1 = new Ispit(1);
$i2 = new Ispit(3);

$s1 = new Student("Mate Matic");
$s1->dodajIspit($i1);
$s1->dodajIspit($i2);
$s2 = new IzvanredanStudent("Jure Juric");
$s2->dodajIspit($i1);
$s2->dodajIspit($i2);
$s2->dodajIspit($i2);

var_dump($s1);
var_dump($s2);
?>