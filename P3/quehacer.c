/*
Creamos los tipos derivados para poder enviar columnas
*/

// Webs a mirar: http://stackoverflow.com/questions/13521129/receiving-with-mpi-type-vector-in-c

/*
Segundo punto:
*/

MPI_Datatype tipo;
MPI_Type_vector(m,1,n,MPI_INT,&tipo); // m (creo que ancho) = número de elementos totales a recibir, n(creo que alto) = numero de saltos hasta llegar a ese elemento (stride)
MPI_Type_commit(&tipo);

if  (myrank > 0){
	MPI_Recv( void *buf, int count,
	MPI_Datatype datatype, int source,
	int tag, MPI_Comm comm,
	MPI_Status *status );
	//recibir última columna de procesador rank-1 en la columna '0'
	MPI_Recv(f,1, tipo, myrank-1,tag,MPI_COMM_WORLD, &status);
	
}
	
calculo F

if (rank < np-1) {
	
MPI_Send(void* data, int count, MPI_Datatype datatype, int destination, int tag, MPI_Comm communicator)
	//es decir, no soy el último
	//enviar última columna a procesador rank+1
	MPI_Send(f+(n-1), 1, tipo, myrank+1,tag,MPI_COMM_WORLD);
}
MPI_Type_free(&tipo);

/*
Tercer punto:
*/


