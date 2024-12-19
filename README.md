PRAVETZ-8D Plus Project

An 8-bit home computer using a home TV instead of a monitor. 
Programmatically incompatible with Pravets 82 family computers (due to the different architecture). 
An analogue of Oric Atmos. At first, it only works with a tape recorder (after 1990, floppy drives 
for it also appeared, united in one housing with the controller[3]. 
It has improved sound capabilities, through a Yamaha microcircuit. It is widely used for home use 
and for training The extremely attractive price of the model (about 10 times lower than Pravets 82) 
gives high hopes for this model and not a few students have taken their first steps on Pravets 8D.

That's what happened to me. My first personal computer was a Pravetz-8D (Oric Atmos).

About a year ago I remembered my old childhood friend and wondered if I could make one of these.
Of course, first I called my mother to ask her if my old computer was still lying in a basement in my old house. To my great surprise, I found out that she had put it in a briefcase along with a pack of floppy disks.
A little battered and missing a single key, but - WORKING.
Unfortunately, the floppy disk drive and the controller were not preserved.

<img src="imgs/old_friend.jpg" width=200 height=200></img>
<img src="imgs/old_friend-d.jpg" width=200 height=200></img>
<br>

So, first I decided to make my own floppy disk controller. Some time ago I had bought one from Boyan Mitov - a very well made board.
I searched the internet but couldn't find a schematic. I bought a kit (a blank board plus PROMs) which I filled up and with a few extras I got it working. But the person I bought this board from said that there were only the gerbers and no schematic.


So I set out to develop such a controller myself.
And since we are already in the 21st century, I decided to use a Raspberry Pi (RP2040) microcontroller.

After several unsuccessful attempts and a lot of digging on the Internet , I got to assemble a floppy disk controller based on the RP2040 plus the schematic solution of the APPLE II for a floppy disk controller. (<a href = "https://en.wikipedia.org/wiki/Steve_Wozniak">WOZ</a> STATE MACHINE) - a very good solution.


During the development, I also had the idea of ​​making a dynamic ROM. For this purpose, I used another RP 2040 which simulates the operation of a standard 27C128 ROM, but it has the ability to change four pages from one bank on the fly. I set eight banks that can be selected when the system is started.


I put all this together on one board. I also made a keyboard for it and the result is this:
<img src="imgs/p8d-2.jpg" width=200 height=200></img>
<img src="imgs/p8d-1.jpg" width=200 height=200></img>
<br>


