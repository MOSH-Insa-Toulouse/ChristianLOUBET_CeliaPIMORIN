# Projet_MOSH 

# 1. Introduction

Le 25 janvier 2021, nous avons commencé le projet «du capteur au banc de test en open source hardware», ce projet a pour but de vérifier la viabilité de la technologie des capteurs électronique à base de papier. Les capteurs à base papier peuvent être utilisé comme jauges de contrainte pour détecter les déformations: de compression et de traction. Ces capteurs peuvent être fabriqué sans électrodes métalliques en utilisant seulement le graphite issu des crayons à papier. Afin de tester nos capteurs nous avons réalisé notre banc de test et nous exploitons nos capteurs avec un circuit imprimé connecté à une Shield Arduino, ce montage transmet par Bluetooth nos mesures vers l’application APK, nous utilisons cette application sur nos smartphones. 

# 2. Capteur Graphite

![Image of Schéma du principe de fonctionnement du capteur](https://github.com/MOSH-Insa-Toulouse/ChristianLOUBET_CeliaPIMORIN/blob/main/explications%20capteur.png)

La résistance du capteur graphite: Sur le papier est déposé du graphite, des atomes de carbones sont donc à la surface du papier, il y a une distance a entre chacun des atomes. Quand le capteur subit une déformation, sa longueur L s’agrandit/diminue et il en va de même pour la distance a entre les atomes. La déformation du capteur papier fait varier la résistance du capteur, car la longueur du capteur et la distance entre les atomes varie elle aussi. La sensibilité du capteur est très grande car elle dépend de l'effet tunnel qui dépend exponentiellement de la ditance entre le particules. Nos capteurs papier ont une zone nominale d’emploi, il ne faut pas trop déformer les capteurs(la déformation ne doit dépasser les 1 %).Les mines de crayon les plus dures(9H, 7H, 5H...) contiennent une proportion plus élevée de colle argileuse tandis que les mines les plus molles (5B,7B, 9B...) ont une proportion de particules de graphite, moins il y a de graphite sur le papier et plus la résistance du capteur augmente. 

Le principe physique du capteur repose sur les systèmes granulaires. Un système granulaire est un système avec des grains de tailles nanométrique où la conductance intragrain est très grande devant la conductance intergrain. En effet la conductance inter grain est la conductance entre deux particules et la conductance intragrain dépend de la diffusivité de la particule quantique qui depend de l'espacement entre les niveaux d'énergie. 
La conductance dans un système granulaire dépend de la constante de barrière tunnel, l'interdistance, l'energie de chargement et de la température.

# 3. Code Arduino
Quand nous connectons notre circuit imprimé avec le Shield Arduino, les pin Rx et Tx du circuit sont connectés aux ports 10 et 11 du Shield. En fait, les port 0 et 1 du Shield sont automatiquement reconfigurés : pin 0 et pin1 deviennent Rx et Tx, il devient donc impossible d’utiliser ces 2 ports, les port 10 et 11 sont donc redéfinies sur le code pour pouvoir transmettre les informations par le module HC-05.
Nous avons codé plusieurs fonctions sur Arduino, la première permet de transmettre par Bluetooth la valeur de la tension aux bornes du capteur papier, la tension est codée en binaire et envoyée par paquet de 10 bit, la seconde fonction affiche les valeurs de la tension (mesuré en Volt, il y a une conversion qui est faite dans le code) et la valeur de la résistance (en Ohm) sur l’écran OLED, Il faut noter que les mesures sont prises toutes les 20 millisecondes. 

# 4. Code APK
Sur ce code APK, nous avons organisé la face avant avec un canvas pour représenter graphiquement la résistance du capteur en temps réel, nous pouvons nous connecter par Bluetooth en sélectionnant les appareils détectables par le smartphone. Notre code traite les données envoyées par Bluetooth, il calcule la valeur de la résistance.

# 5. La Shield
Nous avons pu souder notre circuit imprimé sans court-circuit, nous avons soudé 4 ports femelles supplémentaires : 2 pour connecter les pinces qui sont reliées au capteur papier et 2 autres afin de changer plus facilement la résistance R2, cette résistance fait varier la valeur du gain d’amplification, notre Shield Arduino est alimentée sous 5 Volt, mais en fonction de la quantité de graphite déposée sur le capteur et de la valeur de R2, notre signal peut saturer à 5 Volt ou bien être tellement faible qu’il n’ai pas détectable. 
Enfin, nous avons des ports pour connecter l’écran OLED, l’encodeur rotatoire et le module Bluetooth.

Sur KiCad, nous avons créé des emplacements pour les connecteurs du module HC-05, de l’écran OLED, de l’encodeur rotatoire, de l’amplificateur et le capteur papier. Sur la schématique, nous avons dessiné le montage transimpédance (Filtre passe-bas + montage amplificateur)
Nous avons routé les différents emplacements entre eux, toutes les masses sont reliée par un plan de masse. 

# 6. Le Protocol pour le banc de test

Au début nous déformions notre capteur avec un banc de test cylindrique mais nous avions des mesures aberrantes, c’est en montrant nos résultats à notre professeur que nous avons compris l’origine du problème: les rayons de courbure du cylindre sont trop grands et cela fait dépasser la zone nominale d’emploi de nos capteurs. Sur conseil de Monsieur Grisolia, nous avons utilisé un autre banc de test: avec du ruban adhésif, nous fixons les pinces du capteur sur le bord d’une table, nous mettions une règle sous l’extrémité du capteur qui dépasse de la table. Avec la règle nous déformions le capteur, nous la faisions glisser très légèrement vers le haut. Cela permet de mieux contrôler la déformation du capteur.


