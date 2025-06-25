# Proyecto Final C++ — Conversor de Unidades

¡Hola gente!

Este proyecto ya tiene toda la **estructura base implementada**: el menú se abre correctamente, pero aún no hace nada más.  
Todos los métodos que tienen que implementar **ya están escritos como stubs** (vacíos con comentarios), así que su tarea será completarlos. Yo ya lo hice para asegurarme que funciona y no los pondré a cazar fantasmas.

> 💡 **El profesor no ha cubierto mucho de lo necesario** para este proyecto. Hemos pasado más tiempo hablando del método de evaluación que practicando cómo pedir dos números, validar datos, manejar entradas o crear un menú. Así que sí, hay un saltico… pero sobrevivimos 💪




## 📦 ¿Cómo descargo el proyecto?

Si ya tienen acceso al GitHub, simplemente ejecuten este comando:

```bash
git clone --branch development --single-branch git@github.com:Ing-jdum/PFinalCPP2.git
```

## 🚀 Cómo compilar y ejecutar el proyecto

-- Paso 1: Limpia archivos compilados previos (opcional pero recomendado)
``` bash
make clean
```
-- Paso 2: Compila el proyecto completo
``` bash
make 
```

-- Paso 3: Ejecuta el programa
``` bash
./main
```

-- 💡 Si estás en una subcarpeta distinta, asegúrate de estar en la raíz del proyecto antes de ejecutar estos comandos.

-- 📍 Si estás en la carpeta tests y quieres correr los tests:
cd tests
make run

## 🧭 Orden sugerido para implementar los métodos
Con base en cómo están organizadas las clases y su dependencia entre ellas, este es el orden recomendado para implementar el código:

``` bash
1. Validation Class (utils/Validation.cpp)
¿Por qué primero? Es la base fundamental - todas las demás clases dependen de estas funciones para validar entrada de usuario.

Métodos a implementar:

isValidDouble() - Validar números decimales
isValidInt() - Validar enteros (ya implementado)
trim() - Remover espacios (ya implementado)
toLowerCase() - Convertir a minúsculas
isValidUnitName() - Validar nombres de unidades
2. InputHandler Class (ui/InputHandler.cpp)
¿Por qué segundo? Maneja toda la entrada del usuario usando las validaciones del paso 1.

Métodos a implementar:

getDouble() - Obtener entrada de double validada
getYesNo() - Obtener confirmación sí/no
waitForEnter() - Pausar y esperar Enter
3. LoanCalculator Class (core/LoanCalculator.cpp)
¿Por qué tercero? Lógica de negocio central para cálculos de préstamos.

Métodos a implementar:

calculateMonthlyPayment() - Usar fórmula de pago mensual
calculateLoan() - Calcular detalles completos del préstamo
generatePaymentSchedule() - Crear tabla de pagos
4. CreditAnalyzer Class (core/CreditAnalyzer.cpp)
¿Por qué cuarto? Usa los cálculos del LoanCalculator para análisis de crédito.

Métodos a implementar:

evaluateCredit() - Evaluar perfil crediticio
calculateDebtToIncomeRatio() - Calcular ratio deuda/ingreso
calculatePaymentToIncomeRatio() - Calcular ratio pago/ingreso
Este orden asegura que cada clase tenga sus dependencias ya implementadas
```

## Estructura

```

+----------------------------+
|       CreditProfile       |   <-- Estructura de entrada del usuario
+----------------------------+
| - monthlyIncome: double    |
| - debtLevel: double        |
| - creditScore: int         |
| - loanAmount: double       |
| - monthlyPayment: double   |
+----------------------------+

+----------------------------+
|        CreditResult        |   <-- Resultado de la evaluación crediticia
+----------------------------+
| - decision: CreditDecision |
| - reason: string           |
| - maxLoanAmount: double    |
| - recommendedPayment: double |
+----------------------------+

+----------------------------+
|       CreditAnalyzer       |   <-- Analiza si un perfil califica para préstamo
+----------------------------+
| + evaluateCredit(CreditProfile): CreditResult
| + calculateDebtToIncomeRatio(income, debt): double
| + calculatePaymentToIncomeRatio(income, payment): double
+----------------------------+

+----------------------------+
|         LoanDetails        |   <-- Resultado del cálculo del préstamo
+----------------------------+
| - loanAmount: double       |
| - annualInterestRate: double
| - termInMonths: int        |
| - monthlyPayment: double   |
| - totalAmount: double      |
| - totalInterest: double    |
+----------------------------+

+----------------------------+
|      PaymentSchedule       |   <-- Detalle mensual del préstamo
+----------------------------+
| - month: int               |
| - payment: double          |
| - principal: double        |
| - interest: double         |
| - remainingBalance: double |
+----------------------------+

+----------------------------+
|       LoanCalculator       |   <-- Calcula pagos y cronogramas
+----------------------------+
| + calculateLoan(loanAmount, rate, term): LoanDetails
| + generatePaymentSchedule(LoanDetails): vector<PaymentSchedule>
| + calculateMonthlyPayment(amount, rate, term): double
+----------------------------+

+----------------------------+
|        InputHandler        |   <-- Entrada validada del usuario
+----------------------------+
| + getString(prompt): string
| + getDouble(prompt): double
| + getInt(prompt): int
| + getYesNo(prompt): bool
| + waitForEnter(): void
+----------------------------+

+----------------------------+
|         Validation         |   <-- Validación de datos ingresados
+----------------------------+
| + isValidDouble(str): bool
| + isValidInt(str): bool
| + isValidUnitName(str): bool
| + trim(str): string
| + toLowerCase(str): string
+----------------------------+

+----------------------------+
|           Menu             |   <-- Controla el flujo del programa
+----------------------------+
| + run(): void
| - showMainMenu(): void
| - handleLoanSimulator(): void
| - handleCreditAnalysis(): void
+----------------------------+

```
📝 Explicación rápida para estudiantes:
CreditProfile es la información financiera que el usuario ingresa.

LoanCalculator usa esos datos para calcular cuotas mensuales, interés total y cronogramas.

CreditAnalyzer analiza si el usuario califica para el préstamo.

CreditResult muestra el resultado de esa evaluación.

InputHandler y Validation garantizan que lo que el usuario ingresa sea correcto.

Menu es el controlador principal que organiza todo el flujo de la app.

## 🤖 ¿Puedo usar la AI?
Claro que sí, pero úsala con cabeza. Podrías hacer todo esto en 10 minutos con ChatGPT, pero si no entiendes lo que hace, nos vas a quemar en la exposición.

Aquí un buen prompt para que te ayude mientras aprendes:

Prompt recomendado
Ayúdame a codificar pero a aprender mientras lo hago. Explica cada decisión de estructura de datos que tomes y descríbemela como si fuera nuevo en programación. + estructura en texto plano del proyecto.

Esta es la estructura del proyecto: Entran aqui y le pegan el contenido a gpt, es una versión en texto plano del proyecto:
https://uithub.com/Ing-jdum/PFinalCPP2/tree/development
Pídele que comente bien su código. Pregunta todo lo que no entiendas.

## 📦: Cómo hacer commit y push en GitHub

-- Paso 1: Verifica los archivos modificados
``` bash 
git status
```

-- Paso 2: Añade los archivos al área de preparación (staging)
``` bash 
git add .
```

-- Paso 3: Crea un commit con un mensaje descriptivo
``` bash 
git commit -m "Implementé la clase Unit con sus métodos"
```

-- Paso 4: Envía tus cambios al repositorio remoto (GitHub)
``` bash 
git push origin development
```

## 📣 Dudas
Me pueden escribir si tienen preguntas. No prometo responder de una vez, pero siempre respondo. Échenle ganas.
