#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"


using namespace std;

class estudiante : public persona {
private: string codigo;
	   int id = 0;
	   
public:
	estudiante() {}
	estudiante(string nom, string ape, string dir, int tel, string fn, string c, int i) : persona(nom, ape, dir, tel, fn) {
		codigo = c;
		id = i;
	}


	void setId(int i) { id = i; }
	void setNit(string c) { codigo = c; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	
	int getId() const { return id; }
	string getcodigo() const { return codigo; }
	string getNombres() const { return nombres; }
	string getApellidos() const { return apellidos; }
	string getDireccion() const { return direccion; }
	int getTelefono() const { return telefono; }
	string getFecha_Nacimiento() const { return fecha_nacimiento; }

	
	void borrar() {
		int q_estado;
		conexionBD cn = conexionBD();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getconectar()) {
			string  borrar =
				"delete from clientes  where id_cliente = " + ii + "";
			const char* i = borrar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar() {
		int q_estado;
		conexionBD cn = conexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ii = to_string(id);
		if (cn.getconectar()) {
			string  actualizar =
				"update clientes set nit = '" + codigo + "', nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono =" + t + ", fecha_nacimiento='" + fecha_nacimiento + "' where id_cliente = " + ii + "";
			const char* i = actualizar.c_str();
			
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear() {
		int q_estado;
		conexionBD cn = conexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getconectar()) {
			string  insertar =
				"INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};