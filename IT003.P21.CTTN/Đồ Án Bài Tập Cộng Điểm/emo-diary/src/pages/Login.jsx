import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import "../Login.css"; // đảm bảo đã tạo file Login.css đúng vị trí

export default function Login() {
  const [email, setEmail] = useState("");
  const [pw, setPw] = useState("");
  const [isLogin, setIsLogin] = useState(true);
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    // xử lý đăng nhập ở đây
    alert("Thử submit (chưa kết nối Firebase)");
    navigate("/diary");
  };

  return (
    <div className="login-page">
      <div className="form-box">
        <h2>{isLogin ? "LOGIN QUICK" : "SIGN UP"}</h2>
        <form onSubmit={handleSubmit}>
          <input
            type="email"
            placeholder="E-mail"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            required
          />
          <input
            type="password"
            placeholder="Password"
            value={pw}
            onChange={(e) => setPw(e.target.value)}
            required
          />
          <a href="#" className="forgot">Forgot Password?</a>
          <button type="submit">{isLogin ? "Login" : "Sign up"}</button>
        </form>
        <p onClick={() => setIsLogin(!isLogin)} className="toggle">
          {isLogin ? "Chưa có tài khoản? Đăng ký" : "Đã có tài khoản? Đăng nhập"}
        </p>
      </div>
    </div>
  );
}
