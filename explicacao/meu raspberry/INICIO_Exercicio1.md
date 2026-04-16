Aqui tens a tua intro + respostas **adaptadas, corrigidas e organizadas**, prontas para pôr no relatório 👇

---

## Introdução – PL5 EXERCICIO I | Exercício II (LKM Blinker)

Neste exercício pretende-se compreender o funcionamento de um **Loadable Kernel Module (LKM)** no Linux, em particular:

* identificar o **ponto de entrada do módulo**
* compreender a interação entre **kernel space e user space**
* perceber como um driver implementa um **character device**

Num programa *user-space*, o ponto de entrada é a função:

```c
main()
```

No entanto, num **LKM**, o raciocínio é diferente:

* não existe `main()`
* o kernel utiliza **macros de registo**
* essas macros associam eventos do kernel a funções do módulo

Em particular:

* `module_init(...)` inicia
* `module_exit(...)` termina
`.

---

# Exercício I

---

## 2.1) Which function is executed when this module is loaded?

A função executada quando o módulo é carregado é:

```c
blinker_init
```

Isto porque no final do ficheiro aparece:

```c
module_init(blinker_init);
```

Esta macro regista `blinker_init` como ponto de entrada do módulo.

---

## 2.2) How do you show that this is a character device driver?

Este módulo é um **character device driver** porque:

1. Regista um dispositivo com:

```c
register_chrdev(0, MODULE_NAME, &blinker_fops);
```

módulo implementa um character device.

2. Define uma estrutura:

```c
struct file_operations blinker_fops
```

interface do dispositivo:

* `open`
* `read`
* `write`
* `release`

3. Cria uma interface em user space:

```c
device_create(...)
```

aceder ao driver/:

```bash
/dev/blinker
```

---

## 2.3) What is the major number for this device driver?

O **major number** é atribuído dinamicamente pelo kernel.

* A função:

```c
register_chrdev(...)
```

devolve o major number

* Esse valor é guardado em:

```c
blinker_major
```

* E é mostrado através de:

```c
printk(...)
```

no `dmesg`

* é decidido em runtime

---

## 2.4) When is the pisca_read function called? How is that defined?

A função `pisca_read` (= `blinker_read`) é chamada quando um processo realiza uma operação de leitura sobre o device.

```bash
cat /dev/blinker
```

### Cadeia de execução:

```text
cat → syscall read() → kernel → file_operations → blinker_read
```

```c
register_chrdev(...)
```

---

## 2.5) When is the pisca_write function called? How is that defined?

A função `pisca_write` (= `blinker_write`) é chamada quando um processo realiza uma operação de escrita no device.

---

## 2.6) When is the my_timer_func function called? How is that defined?

A função `my_timer_func` é chamada sempre que o **timer do kernel expira**.

---

### Funcionamento:

1. O timer expira
2. O kernel chama:
3. No final da função:

```c
add_timer(&my_timer);
```

comportamento periódico

---

### Conclusão

`my_timer_func`:

* não é chamada por user space
* não depende de `/dev`
* é chamada **automaticamente pelo kernel**
* implementa o comportamento de **blinking**

---

Se quiseres, no próximo passo podemos fazer o mesmo para o **Exercício III (software PWM)** — que é onde a coisa fica mesmo interessante 💥
