
 
   Entry(int columnNumber, double data) // changed int to object.

      Entry(Entry other) // changed int to object.

      int getColumn();
      void setData(double x)
      double getData()
      String toString()
      
      // equals(): overrides Object's equals() method
      public boolean equals(Object x) 

   // Constructor. Precondition n >= 1.
   Matrix(int n)

// Access Functions --------------------------------------------------------


   int getSize()

   int getNNZ()

   // Returns true if two matrices are equal. False otherwise.
   boolean equals(Object x)

   void makeZero()
   Matrix copy()

   // changeEntry()
   // pre: 1<=i<=getSize(), 1<=j<=getSize()
   // changes ith row, jth column of this Matrix to x
   void changeEntry(int i, int j, double x)
    
   // returns a new Matrix that is the scalar product of this Matrix with x
   Matrix scalarMult(double x)
	 
   // returns a new Matrix that is the sum of this Matrix with M
   // pre: getSize()==M.getSize()
   Matrix add(Matrix M)

   // sub()
   // returns a new Matrix that is the difference of this Matrix with M
   // pre: getSize()==M.getSize()
   Matrix sub(Matrix M)

   // returns a new Matrix that is the transpose of this Matrix 
   Matrix transpose()
    
   // mult()
   // returns a new Matrix that is the product of this Matrix with M
   // pre: getSize()==M.getSize()
   Matrix mult(Matrix M)

   // Other Functions ---------------------------------------------------------

   // toString()
   // Overides Object's toString() method.
   String toString()

   // dot()
   // Takes the dot product of two lists.
   private static double dot(List P, List Q)
   
   // Helper Functions --------------------------------------------------------

   List addHelper(List a, List b, boolean isSum)
