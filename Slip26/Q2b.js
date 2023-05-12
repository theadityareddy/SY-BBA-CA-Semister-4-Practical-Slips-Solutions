const express = require('express');
const app = express();
const port = 3000;

// Array of products
const products = [
  { id: 1, name: 'Shirt', price: 20 },
  { id: 2, name: 'Pants', price: 30 },
  { id: 3, name: 'Shoes', price: 40 }
];

// Middleware to parse JSON data
app.use(express.json());

// Route to get all products
app.get('/products', (req, res) => {
  res.json(products);
});

// Route to add a product to cart
app.post('/cart/add', (req, res) => {
  const productId = req.body.productId;
  const product = products.find(p => p.id === productId);
  if (product) {
    res.json({ message: `Added ${product.name} to cart.` });
  } else {
    res.status(404).json({ error: 'Product not found.' });
  }
});

// Start the server
app.listen(port, () => {
  console.log(`Department store portal listening at http://localhost:${port}`);
});
