# PL5 - Exercício II: Kernel Module Blinker (Raspberry Pi 4)

## Objetivo

Desenvolver um módulo de kernel para o Raspberry Pi 4 capaz de controlar um LED através de um GPIO, permitindo configurar dinamicamente o período de blinking via interface `/dev/blinker`.

---

## Arquitetura

O sistema está dividido em duas partes:

### Kernel Space

* Timer do kernel (`hrtimer`)
* Controlo direto do GPIO
* Driver com funções:

  * `init` → inicialização
  * `read` → leitura do período
  * `write` → alteração do período

### User Space

* Interface através de:

  * `/dev/blinker`
* Interação via comandos Linux (`cat`, `echo`, `tee`)

---

## Ficheiros principais

* `blinker.c` → lógica principal do driver
* `gpio.c / gpio.h` → abstração do GPIO
* `Makefile` → compilação do módulo
* `blinker-rpi4.ko` → módulo gerado

---

## GPIO Utilizados

Foram utilizados os seguintes pinos do Raspberry Pi (numeração física):

- Pino 5 → GPIO3 
- Pino 7 → GPIO4 

A escolha segue o setup realizado em aula, garantindo consistência entre ambiente de desenvolvimento e testes.

O LED foi ligado:
- GPIO4 (pino 7) → resistência → LED → GND

---

## Compilação

```bash
make
```

Gera:

```bash
blinker-rpi4.ko
```

---

## Execução

### Carregar módulo

```bash
sudo insmod blinker-rpi4.ko
```

### Ver logs do kernel

```bash
dmesg -W
```

---

## Interface `/dev/blinker`

### READ (ler período atual)

```bash
sudo cat /dev/blinker
```

Exemplo:

```
2000
```

---

### WRITE (alterar período)

```bash
echo 1000 | sudo tee /dev/blinker
```

ou

```bash
sudo sh -c "echo 1000 > /dev/blinker"
```

---

## Validação

Testes realizados:

| Ação                       | Resultado       |
| -------------------------- | --------------- |
| `cat /dev/blinker` inicial | 2000 ms         |
| `write 1000`               | LED mais rápido |
| `cat` após write           | 1000 ms         |
| `write 4000`               | LED mais lento  |
| `cat` final                | 4000 ms         |

✔ Timer funcional
✔ GPIO controlado corretamente
✔ Interface `/dev` operacional
✔ Comunicação user ↔ kernel validada

---

## Hardware

* Raspberry Pi 4
* LED
* Resistência (~220–330Ω)
* GPIO12 (output)
* GND comum

---

## Conclusão

O módulo permite:

* controlo dinâmico do período de blinking
* comunicação entre user space e kernel space
* validação prática de drivers Linux com GPIO

✔ Exercício concluído com sucesso

---
