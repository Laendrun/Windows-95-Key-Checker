# Windows 95 Key Checker

I saw today an article about someone who asked ChatGPT to generate Windows 95 key for him giving the exact format of the activation key.

I then made some research, and now I want to implement a simple Microsoft Windows 95 activation key checker, that checks if a key is a valid Windows 95 activation key or not.

## Quick intro to activations key

## Windows 95 Activation Key format

The activation keys have different format based on if it was a personal key (the one you get on a Windows 95 installation CD), or if it is an OEM key (this one is generally used in enterprise context).

### Personal Activation Key format

The format of the personal activation key is the following :

```XXX-YYYYYYY```

Let's break it down a little more.

```XXX```: These first 3 characters can be anything (when I say ANYTHING, I mean ANYTHING) except the following :

- 333
- 444
- 555
- 666
- 777
- 888
- 999

In the decompiled code from the original check function, the string is converted to an int, using the `atoi` function, but the only thing that is check for the first 3 characters, is that they are not part of the above list.

After these first 3 characters, there should be a `-`, this one's also not checked, so basically the 4 first characters can be *almost* anything you want.

`YYYYYYY`: These last 7 characters have to be digits, and the only thing that is checked against these characters is that the sum of all of them has to divisable by 7 with no remainder (Modulo 7 check basically).

These are the *only* checks that are done against the key to check if it is valid or not, so below I'll put some valid Win95 Personal Keys, and also why they are valid.

- YOLO0000000
	- The first 3 characters are not in the exclusion list above
	- The `-` is not checked so it can be anything
	- The modulo 7 of the sum of the 7 last digits is 0
- 000-0000000
	- The first 3 characters are not in the exclusion list above
	- I kept the `-` as in the default format
	- The mod7 check is the same as the one above

I think you got the point, Windows 95 is easy to activate, not used anymore but easy to activate.

### OEM Activation Key format

The format of the OEM key is the following :

`AAABB-OEM-XXXXXXX-CCCCC`

Let's break it down a little more :

`AAA`: an integer between 0 - 366 (The day of the year index, including leap year)

`BB`: an integer between 03 - 95

`-OEM-`: this string as to be as is, in the key, at this exact place

`XXXXXXX`: seven digits that have to respect the same mod7 rule as the personal key

`-`: This dash has to be there

`CCCCC`: these last 5 characters are random, they can be anything, this is not checked at all.

### Sources

Quick 6 min youtube video to look into it in more details:

[Why 111-1111111 is a valid Windows 95 Key](https://www.youtube.com/watch?v=cwyH59nACzQ&list=WL)

An article, that basically tests the same thing as the youtube video above, but in text format (my code is mostly based on what's describe in this article):

[Reversing Microsoft’s Windows95 Product Key Check Mechanism](https://infosecwriteups.com/reversing-microsofts-windows95-product-key-check-mechanism-ca7e825014b6)
