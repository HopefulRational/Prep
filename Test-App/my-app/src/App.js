import React, { useState } from 'react';
import { Button } from './components/ui/button.js';
import { Input } from './components/ui/input.js';
import { Card, CardHeader, CardTitle, CardContent, CardFooter } from './components/ui/card.js';
import { User, Lock } from 'lucide-react';

export default function LoginPage() {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [isLoading, setIsLoading] = useState(false);
    const [error, setError] = useState(null);
  
    const handleLogin = async (e) => {
      e.preventDefault();
      if (!email || !password) {
        setError('Please fill in all fields');
        return;
      }
  
      setIsLoading(true);
      setError(null);
      try {
        // Simulate an API call
        await new Promise((resolve, reject) => setTimeout(() => reject('Invalid credentials'), 2000));
      } catch (error) {
        setError('Invalid email or password');
      } finally {
        setIsLoading(false);
      }
    };
  
    return (
      <div className="login-container">
        <Card className="login-card">
          <CardHeader>
            <CardTitle className="text-2xl font-bold text-center">Login</CardTitle>
          </CardHeader>
          <form onSubmit={handleLogin}>
            <CardContent className="space-y-4">
              {error && <div className="text-red-500 text-sm">{error}</div>}
              <div className="relative">
                <div className="absolute inset-y-0 left-0 flex items-center pl-3 pointer-events-none">
                  <User className="w-5 h-5 text-gray-500" />
                </div>
                <Input
                  id="email"
                  value={email}
                  onChange={(e) => setEmail(e.target.value)}
                  className="pl-10 pr-3 py-2 border-2 border-gray-300 rounded focus:outline-none focus:ring-2 focus:ring-blue-500"
                  placeholder="Email"
                  aria-label="Email"
                />
              </div>
              <div className="relative">
                <div className="absolute inset-y-0 left-0 flex items-center pl-3 pointer-events-none">
                  <Lock className="w-5 h-5 text-gray-500" />
                </div>
                <Input
                  id="password"
                  type="password"
                  value={password}
                  onChange={(e) => setPassword(e.target.value)}
                  className="pl-10 pr-3 py-2 border-2 border-gray-300 rounded focus:outline-none focus:ring-2 focus:ring-blue-500"
                  placeholder="Password"
                  aria-label="Password"
                />
              </div>
            </CardContent>
            <CardFooter className="flex justify-between">
              <Button type="submit" className="w-full" disabled={isLoading}>
                {isLoading ? 'Logging in...' : 'Login'}
              </Button>
            </CardFooter>
          </form>
        </Card>
      </div>
    );
  }  