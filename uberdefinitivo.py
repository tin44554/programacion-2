class Usuario:
    def __init__(self, id_usuario, nombre, correo, telefono):
        self.id_usuario = id_usuario
        self.nombre = nombre
        self.correo = correo
        self.telefono = telefono

class Conductor:
    def __init__(self, id_conductor, nombre, licencia, telefono):
        self.id_conductor = id_conductor
        self.nombre = nombre
        self.licencia = licencia
        self.telefono = telefono

class Vehiculo:
    def __init__(self, placa, marca, modelo, color):
        self.placa = placa
        self.marca = marca
        self.modelo = modelo
        self.color = color

    def tipo_servicio(self):
        return "Vehículo genérico"

class UberX(Vehiculo):
    def __init__(self, placa, marca, modelo, color, aire_acondicionado):
        super().__init__(placa, marca, modelo, color)
        self.aire_acondicionado = aire_acondicionado

    def tipo_servicio(self):
        return "UberX"

class UberVan(Vehiculo):
    def __init__(self, placa, marca, modelo, color, capacidad):
        super().__init__(placa, marca, modelo, color)
        self.capacidad = capacidad

    def tipo_servicio(self):
        return "UberVan"

class UberBlack(Vehiculo):
    def __init__(self, placa, marca, modelo, color, lujo=True):
        super().__init__(placa, marca, modelo, color)
        self.lujo = lujo

    def tipo_servicio(self):
        return "UberBlack"

class MetodoPago:
    def __init__(self, id_pago, tipo, detalles):
        self.id_pago = id_pago
        self.tipo = tipo
        self.detalles = detalles

class Viaje:
    def __init__(self, usuario, conductor, vehiculo, metodo_pago, destino, tarifa):
        self.usuario = usuario
        self.conductor = conductor
        self.vehiculo = vehiculo
        self.metodo_pago = metodo_pago
        self.destino = destino
        self.tarifa = tarifa  # nueva propiedad

    def mostrar_info(self):
        print("\n===== DETALLES DEL VIAJE =====")
        print(f"Usuario: {self.usuario.nombre} ({self.usuario.telefono})")
        print(f"Conductor: {self.conductor.nombre} - Licencia: {self.conductor.licencia}")
        print(f"Tipo de Uber: {self.vehiculo.tipo_servicio()}")
        print(f"Vehículo: {self.vehiculo.marca} {self.vehiculo.modelo} - Placa {self.vehiculo.placa}")
        print(f"Color: {self.vehiculo.color}")
        print(f"Método de pago: {self.metodo_pago.tipo} ({self.metodo_pago.detalles})")
        print(f"Destino: {self.destino}")
        print(f"Tarifa estimada: ${self.tarifa}")  # mostrar la tarifa


# instancias de usuario, conductor y vehículos
usuario1 = Usuario(1, "Antonio", "antonio@mail.com", "3124567890")

conductor1 = Conductor(101, "Carlos", "LIC12345", "3109876543")

uberx = UberX("ABC123", "Toyota", "Corolla", "Negro", aire_acondicionado=True)
ubervan = UberVan("XYZ987", "Hyundai", "H1", "Blanco", capacidad=8)
uberblack = UberBlack("JKL456", "BMW", "Serie 5", "Negro")

# método de pago
pago1 = MetodoPago(201, "Tarjeta", "Visa terminada en 1234")

# viajes con tarifa incluida
viaje1 = Viaje(usuario1, conductor1, uberx, pago1, "Centro Comercial", 15000)
viaje2 = Viaje(usuario1, conductor1, ubervan, pago1, "Aeropuerto", 35000)
viaje3 = Viaje(usuario1, conductor1, uberblack, pago1, "Hotel 5 Estrellas", 60000)

viaje1.mostrar_info()
viaje2.mostrar_info()
viaje3.mostrar_info()

