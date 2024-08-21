# RTFM #

So you got an AND!XOR DEF CON 32 HackBoi badge? Here's what you should know...

## TLDR ##

1. It plays DooM (poorly? but still goodish, right?)
2. It has a few remaining challenges 
3. Do NOT put AA batteries in this, it uses 14500 Li-Ion rechargable batteries (button top). You shouldnt have to replace them unless you get drunk and lose them.

# License(s) #

Made with beer and late nights in California.

(C) Copyright 2017-2024 AND!XOR LLC (https://andnxor.com/).

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Third Party Licenses...

* Any code derived from chocolate-doom matinains its existing license (generally GPLv2)
* New RP2040 Doom specific code not implementing existing chocolate-doom interfaces is licensed BSD-3
* ADPCM-XA is unmodified and is licensed BSD-3
* Modified emu8950 derived code retains its MIT license
* See the license files in our repo for other details

**ADDITIONALLY:**

If you find this source code useful in any way, use it in another electronic
conference badge, or just think it's neat. Consider buying us a beer
(or two) and/or a badge (or two). We are just as obsessed with collecting
badges as we are in making them.

**Contributors:**

* @andnxor
* @zappbrandnxor
* @hyr0n1
* @Cr4bf04m
* @lacosteaef
* @f4nci3
* @kur3us
* @ellwoodthewood
* @mlaan
* @5n4ck3y

**Sponsors:**
* Urbane Security - https://urbanesecurity.com/
* Macrofab - https://www.macrofab.com/
* CTFd - https://ctfd.io/
* Philanthropists

# Hardware #
* MCU - Raspberry Pi Pico RPI2040
* Flash - Winbond 25Q128JVSM
* LEDs - APA102-2020-8a
* Batteries - Xtar-14500-800
* Charging Circuit - Custom Designed by Crabf0am
* Crabf0am & Hyr0n 3D Printed PLA+ LCD Window Frames  
* Macrofab PCB Assembly


# DOOM #

Our variant of DooM is a fork, of a fork, of a fork, of RP2040 DooM by Kilograham (https://github.com/kilograham/rp2040-doom), which is a fork, of a fork, of a fork, of Vanilla Doom source released by Id Software. For now, here's the bullet points...

**Controls**

* Up = Forward
* Down = Backward
* Left = Turn Left
* Right = Turn Right
* Select = Escape Key (Back Up in Menu)
* Start = Return Key (Select) & Change Weapon
* A = Fire
* B = Action
* B (Hold) + Start (Tap) = Display Map

**Load An Alternate WAD**
* Install Picotool: https://github.com/raspberrypi/picotool
* Read the documentation, clone the RP2040 Doom repo, and build the WHD Tool: https://github.com/kilograham/rp2040-doom, or if you trust us there are pre-compiled versions for Ubuntu/Debian Linux as well as MacOS (these are located in /tools). You have to convert the WAD to WHD format.
* Put the badge in BOOTSEL mode, then use picotool to copy the output WHD file to address 0x10060000
* PAY ATTENTION TO THIS DETAIL: There is a big difference between IWADs and PWADs (patch WADs), google it. Most WADs you find on the interwebs are rightfully so, PWADs; they patch the existing IWAD with new lumps. You do not have a file system on the badge with an existing IWAD, so the loading of two WADs (such as done on your PC is not possible). Also we did not have enough storage to accomodate this. If there is a PWAD you really want to play, fire up SLADE (Its a Doom Editor) and copy over the assets from the PWAD (e.g. maps, music) into our CTF WAD provided in this repo. The WAD in our repo, is a hand crafted IWAD forked from FreeDoom to match a Chocolate Doom MegaWad and abide by no limit removing features... DooM as it was meant to be played. If you already have a license for Doom feel free to use your legally obtained WAD and follow the similar process to overwrite the lumps with whatever is in your PWAD. This also means you can NOT have MIDI music, it must be in MUS format (which SLADE can convert) to be converted from WAD to WHD format using the conversion tool by Kilograham.
```
neckbeard@lappy486:~$ whd_gen_linux input.wad output.whd -no-super-tiny
neckbeard@lappy486:~$ picotool load -v -t bin output.whd -o 0x10060000
```
**BOOTSEL Mode**
* Install picocom
* Ensure badge is powered off, turn it on, and open a serial connection within the first 2 seconds using baud rate 1337
* An example, assuming you use Linux and that this is the only serial device attatched so it mounts at ttyACM0, is below
* If you need a MacOS example feel free to @zapp
```
neckbeard@lappy486:~$ sudo apt-get install picocom
neckbeard@lappy486:~$ picocom -b 1337 /dev/ttyACM0
```

# 5n4ck3y (aka Snackey) Contest #

The newest member of AND!XOR, fully responsible for handing out free badges. Intern 4 life. Look for them in the conference... 

If your summercamp-fam are jealous and want to earn a free badge through hacking challenges, go see 5n4ck3y in the DEF CON Contest Area.

Let's explain 5n4ck3y, the challenge, and how this all pulls together. 
* 5n4ck3y (aka Snackey) is the vending machine dispensing badges
* The challenge scoreboard for both 5n4ck3y & HackBoi are hosted on the CTFd 5n4ck3y Challenge site (see links below). Yes, you hack on challenges to earn a badge and it continues once you have a badge in your possession. It's a cumulative scoreboard.

The general process one will follow:

1. Register at 5n4ck3y Challenge with a REAL e-mail address.
2. The first challenge is IRL physical verification with 5n4ck3y (look at the screen), this will unlock badge dispensing challenges in CTFd.
3. Solve five and earn a badge.

Instructions for physical verification(s) are on the specific challenge group of the CTFd site.

# Troubleshooting #
If you are having issues with the badge for any reason, try the #dc32 channel of our Discord. You could also swing by the contest area.

Given the structure of our discord channels, this is what is meant for what:

Channel -> Subchannel
* 5n4ck3y -> General banter and Q&A about 5n4ck3y
* Badge & CTF -> DC32 :: General collaborative non-spoiler discussion for people working on badge challenges and if there are any issues try crowdsourcing troubleshooting here if we cant get to you right away.

## Hardware Issues  ##

* Nothing happens when I turn it on & something on the top back is getting hot
    * TURN IT OFF AND REMOVE POWER!
    * 99% of the time this means there is a short on one of the LEDs. If it worked previously, this means the HackBoi was banged around and a cold solder joint snapped and now there is a short.
    * Dissassemble, apply hot air to each LED on the front of the badge: 250 Degrees Celcius at 10 seconds each. Let it cool and you are good to go. Usually.

* LED(s) is/are missing
    * There were issues in sourcing our LEDs. One week before DEF CON 32, we huddle up in garages, fabs, and hotel rooms to hand solder (hot air) and reflow LEDs. We got most, but not all of them done. The last of the badges dispensed by 5n4ck3y were missing some LEDs. 
        * If you want to complete it, order the neccesary LEDs (Apa102-2020-8a) at https://www.digikey.com/en/products/detail/adafruit-industries-llc/3341/6578337
        * These are 10 packs, reccomend getting at least 2 packs.
        * Reccomend very minimal lead free solder paste if the pads are bare and do NOT put paste on the middle two pads.
    * Steps Shared in our Discord...
        * LED 1 is the top left most LED (above the USB-C). It should be oriented like this:
        
        ![image](/img/LED1.png)

        * You will see a 1 on the silkscreen right where the + sign is on the diagram above. That orientation is correct for 13 of the 17 LEDs highlighted in yellow.

        ![image](/img/LED2.png)

        * The green highlighted LEDs get rotated 180 degrees.
        * The blue highlighted LEDs get rotated 90 degrees.
        * Pro-tip: Only solder the pads highlighted in green. This will prevent shorts between 3.3v and GND.

        ![image](/img/LED3.png)
    * Welcome to our hell!

# Links #
* Twitter: https://twitter.com/ANDnXOR
* Github: https://github.com/ANDnXOR/ANDnXOR_DC32_Badge
* Discord: https://discord.gg/DeXNEydE2r
* 5n4ck3y Challenge: https://5n4ck3y.ctfd.io/
