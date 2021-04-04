# tcrkbd

This repo contains the firmware for my [Corne keyboard][crkbd_repo].

![A picture of the keyboard][logo]

## Specs

Item | Details
-- | --
PCB | [Corne Classic PCB][pcb]
MCU | [Elite-C v4][mcu]
Display | [128x32 OLED Screen][screen]
Case | [Corne Technician Keyboard Case][case]
Switches | [Gateron Milk Black][switches]
Keycaps | [PBT Flighter][keycaps]

If you would like to build your own Corne keyboard, there are some [notes on this later](#building-your-own).

## Keyboard layout

The keyboard layout consists of 4 layers:

+ Default
+ Numpad
+ Symbols
+ Arrows

The default layer is always active. All of the other layers are accessed using a QMK `MO` keycode. This means that the
layer will only be active while the key with that keycode is held down. The numpad and symbols layer keys are in the
right hand side thumb cluster, and the arrows layer key is in the bottom right hand corner of the right side.

### Default

This is where the letters are. Nothing too fancy but there are some things to note:

+ I'm using Colemak. If you type lots, give it a try. [More on this later](#colemak).
+ The leftmost column consists of:
  + Tab.
  + Escape if pressed, control if held.
  + Shift.
+ Initially I tried having shift above control, but because the Corne only has 3 rows this puts shift where caps lock
  normally is. It's much more natural to have shift on the bottom row and control in the middle row.
+ Space is on the left thumb button and enter is on the right thumb button.
+ Win/OS and Alt are in the thumb cluster of the left side, in that order.

### Numpad

This is where the numbers and most of the symbols are. Under the left hand, I have all the parentheses and some commonly
used symbols such as plus/equals, dash/underscore, backslash/pipe and tilde/backtick.

Under the right hand I have a numpad where the 4 key is under your index finger on the home row. To the left of the 4
key there is a colon which is great for Vim.

### Symbols

All of the symbols (Shift + any number key) are on this layer. 1-5 are on the top row of the left hand, 6-0 are on the
top row of the right hand.

### Arrows

This layer just has the arrow keys arranged in the usual pattern. The left arrow is under the middle finger on the right
hand side. It was more natural to shift the arrow keys one column to the right because the pinky finger (which is used
to activate this layer) doesn't need to stretch as much this way.


## Colemak

If you type lots, whether it be as part of your job or just part of your daily life, you should seriously consider
giving Colemak a go. Your fingers move much less when using Colemak. Look at a
[key usage heatmap](https://www.keybr.com/layouts) of Colemak vs. Qwerty to get an idea of just how bad Qwerty is.

I used the [keybr typing practice](https://www.keybr.com/) website to learn Colemak. It took me about a month of doing
5-10 minutes of daily practice before it became muscle memory. It took an additional few months of every day use (plus a
week or two of changing keyboard layouts to get the symbols in a good spot) before I was back up to what I would
consider a "comfortable typing speed".

Some common questions/bits of information:

+ *"Won't I lose Qwerty if I switch to Colemak?"*
  + It's possible. I avoid this by using Colemak at work and Qwerty at home. Additionally, I only use Colemak on
    ortholinear keyboards, which helps my fingers find the right spot whether I'm using a traditional staggered
    keyboard or an ortholinear one.
+ *"Did you become a faster typist by switching to Colemak?"*
  + No, and I didn't intend to. Don't switch to Colemak if you are just looking for a speed increase. The benefit of
    Colemak is the increase in comfort while typing. This isn't to say that you can't be fast using Colemak. Many of the
    top typists in the world are capable of close to 200WPM in multiple keyboard layouts, Colemak included.
+ *"Should I use Colemak keybindings for Vim?"*
  + Under the advice of a friend who uses Colemak, I didn't touch my Vim keybindings. It only took a week or so to be
    back to muscle memory. Using Vim with Qwerty is still muscle memory for me too, but it does take a few minutes to
    adjust if I haven't used Vim outside of work for a week or two.
+ If you do decide to give Colemak a try, **expect to be frustrated.** There were several times when learning Colemak
  where I got frustrated at how slowly I was typing and just went back to a Qwerty keyboard. Don't get discouraged if
  this happens a few times. If you've learned Vim, learning Colemak is much the same process. Full immersion is the key.


## Building your own

The official Corne keyboard repo has a very extensive [build guide][build_guide]. For brevity, I won't repeat it here.

Parts-wise, https://www.littlekeyboards.com/ is a great website. They have kits which come with everything you'll need
(diodes, TRRS jacks, M2 screws, etc), and they're really well priced. I bought my PCB, case and MCUs from
littlekeyboards. The screens were out of stock at the time, so I got some from AliExpress.

As for switches and keycaps, I used https://kbdfans.com/ but there are plenty of other alternatives from which you can
get these parts.


[pic]: assets/tcrkbd.jpg "A picture of the keyboard."
[crkbd_repo]: https://github.com/foostan/crkbd

[pcb]: https://www.littlekeyboards.com/collections/corne-pcb-kits/products/crkbd-classic-essentials-kit
[mcu]: https://www.littlekeyboards.com/collections/mcus/products/elite-c-v3
[screen]: https://www.littlekeyboards.com/collections/oled-screens/products/oled-screen
[case]: https://www.littlekeyboards.com/collections/corne-cases/products/corne-technician-keyboard-case
[switches]: https://kbdfans.com/products/gateron-milk-black-switches
[keycaps]: https://kbdfans.com/products/pg-pbt-flighter-keycaps-set
[build_guide]: https://github.com/foostan/crkbd/blob/master/corne-classic/doc/buildguide_en.md
