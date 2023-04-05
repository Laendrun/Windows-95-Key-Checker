# Windows 95 Key Checker

I saw today an article about someone who asked ChatGPT to generate Windows 95 key for him giving the exact format of the activation key.

I then made some research, and now I want to implement a simple Microsoft Windows 95 activation key checker, that checks if a key is a valid Windows 95 activation key or not.

## Quick intro to activation keys

An activation key, for a software in this case, is a way for a user to authenticate himself.

It let's your computer (or the software publisher) know you paid the software, and have the rights to use it.

Today, a license key is usually checked against a database of valid key somewhere on the Internet, preventing the use of the same key multiple times.

Back in the days, as Internet wasn't as broadly distributed as today, most of the software that required activation keys came with a key validation in the software itself.

It was the case for Windows 95, during the installation, the activation key was verified locally. It was also simpler, since most softwares were bought via a CD or DVD install and the activation key was written on the disk itself.

The advantage of a local check is that it does not require an internet access to validate, but can be more easily tricked.

Let's take a little look at a Windows 10 install.

You can easily download and install Windows 10 on your machine and not activate it. If you need it to be activated for one reason or an other, you can simply buy a license key and have it sent to you via email. Then, when you enter the key you bought it is validated online.

The advantage of having the key validated online is that each and every activation can be disabled by the software publisher if a problem is encounterd.

Bigger companies usually get a really big list of valid license, and when they want to activate one of their computer, they can "simply" ask the computer to pick the first available license in this list.

These list have obviously been leaked on the internet and are still used today by some people to activate their Windows install for free via a simple script.

> (Click [here](https://github.com/Chaxiraxi/Windows-Cracker) to go to one of the repo that does that).

And in that case, the software cannot revoke a single specific license, the whole list has to be revoked, and they don't want to do that to avoid having big companies complain to them since all of their machines will not be activated anymore.

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
